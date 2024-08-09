#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    uploadButton = new QPushButton("Загрузка алгоритма", this);
    findButton = new QPushButton("Поиск старого алгоритма", this);
    updateButton = new QPushButton("Обновление алгоритма", this);

    hsCanRadioButton = new QRadioButton("High-Speed CAN", this);
    lsCanRadioButton = new QRadioButton("Low-Speed CAN", this);
    fdCanRadioButton = new QRadioButton("CAN FD", this);

    autoDetectCheckBox = new QCheckBox("Автоматически определить тип шины CAN", this);

    uploadPathLabel = new QLabel("Путь к загруженному файлу: Не выбран", this);
    findPathLabel = new QLabel("Путь к старому файлу на устройстве: Не найден", this);
    errorLabel = new QLabel("Ошибка: Нет", this);  // Изначально нет ошибок

    // Устанавливаем круглую форму кнопок
    uploadButton->setStyleSheet("border-radius: 50px; padding: 20px;");
    findButton->setStyleSheet("border-radius: 50px; padding: 20px;");
    updateButton->setStyleSheet("border-radius: 50px; padding: 20px;");

    layout->addWidget(autoDetectCheckBox);
    layout->addWidget(hsCanRadioButton);
    layout->addWidget(lsCanRadioButton);
    layout->addWidget(fdCanRadioButton);
    layout->addWidget(uploadButton);
    layout->addWidget(findButton);
    layout->addWidget(updateButton);
    layout->addWidget(uploadPathLabel);
    layout->addWidget(findPathLabel);
    layout->addWidget(errorLabel);  // Добавляем QLabel для ошибок

    setCentralWidget(centralWidget);

    connect(uploadButton, &QPushButton::clicked, this, &MainWindow::onUploadAlgorithmClicked);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::onFindOldAlgorithmClicked);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateAlgorithmClicked);

    connect(hsCanRadioButton, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
    connect(lsCanRadioButton, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
    connect(fdCanRadioButton, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);

    connect(autoDetectCheckBox, &QCheckBox::stateChanged, this, &MainWindow::onCheckBoxStateChanged);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onUploadAlgorithmClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите алгоритм для загрузки", "", "C++ Files (*.cpp *.h);;All Files (*)");
    if (fileName.isEmpty()) {
        setError("Файл не выбран.");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        setError("Не удалось открыть файл.");
        return;
    }

    // Сохранение данных алгоритма в память программы
    algorithmData = file.readAll();
    file.close();

    // Отображаем путь к загруженному файлу
    uploadPathLabel->setText("Путь к загруженному файлу: " + fileName);
    setError("Алгоритм загружен в память.");
}

void MainWindow::onFindOldAlgorithmClicked()
{
    setError("Поиск старого алгоритма начался.");

    QByteArray requestData;  // Создайте запрос для поиска старого алгоритма
    if (!sendDataOverCAN(requestData)) {
        setError("Не удалось отправить запрос через CAN.");
        return;
    }

    QByteArray responseData;
    if (!receiveDataOverCAN(responseData)) {
        setError("Не удалось получить ответ через CAN.");
        return;
    }

    // Для примера, считаем, что в ответе будет путь к старому файлу
    QString oldFilePath = QString(responseData);
    findPathLabel->setText("Путь к старому файлу на устройстве: " + oldFilePath);

    setError("Поиск старого алгоритма завершен.");
}

void MainWindow::onUpdateAlgorithmClicked()
{
    if (algorithmData.isEmpty()) {
        setError("Нет загруженного алгоритма для обновления.");
        return;
    }

    if (findPathLabel->text().contains("Не найден")) {
        setError("Не найден старый алгоритм на устройстве.");
        return;
    }

    if (!sendDataOverCAN(algorithmData)) {
        setError("Не удалось передать данные через CAN.");
    } else {
        setError("Обновление алгоритма завершено.");
    }
}

void MainWindow::onRadioButtonToggled()
{
    if (hsCanRadioButton->isChecked()) {
        qDebug() << "Выбран High-Speed CAN";
    } else if (lsCanRadioButton->isChecked()) {
        qDebug() << "Выбран Low-Speed CAN";
    } else if (fdCanRadioButton->isChecked()) {
        qDebug() << "Выбран CAN FD";
    }
}

void MainWindow::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        detectCanType();
    }
}

void MainWindow::detectCanType()
{
    TPCANMsg message;
    message.ID = 0x123;  // Уникальный идентификатор для тестового сообщения
    message.MSGTYPE = PCAN_MESSAGE_STANDARD;
    message.LEN = 1;
    message.DATA[0] = 0x55;  // Тестовый байт данных

    TPCANStatus status = CAN_Write(PCAN_USBBUS1, &message);
    if (status != PCAN_ERROR_OK) {
        setError("Не удалось отправить тестовое сообщение через CAN.");
        return;
    }

    // Ожидаем ответ от устройства
    TPCANMsg responseMessage;
    TPCANTimestamp timestamp;
    status = CAN_Read(PCAN_USBBUS1, &responseMessage, &timestamp);

    if (status == PCAN_ERROR_OK) {
        qDebug() << "Ответ от устройства получен";
        if (responseMessage.LEN == 1 && responseMessage.DATA[0] == 0xAA) {
            hsCanRadioButton->setChecked(true);
            setError("Определен тип шины CAN: High-Speed CAN.");
        } else if (responseMessage.LEN == 1 && responseMessage.DATA[0] == 0xBB) {
            lsCanRadioButton->setChecked(true);
            setError("Определен тип шины CAN: Low-Speed CAN.");
        } else if (responseMessage.LEN == 1 && responseMessage.DATA[0] == 0xCC) {
            fdCanRadioButton->setChecked(true);
            setError("Определен тип шины CAN: CAN FD.");
        } else {
            setError("Не удалось определить тип шины CAN.");
        }
    } else {
        setError("Не удалось получить ответ от устройства через CAN.");
    }
}

bool MainWindow::sendDataOverCAN(const QByteArray &data)
{
    TPCANMsg message;
    message.ID = 0x123;  // Замените на необходимый идентификатор CAN
    message.MSGTYPE = PCAN_MESSAGE_STANDARD;
    message.LEN = data.size();
    memcpy(message.DATA, data.data(), message.LEN);

    TPCANStatus status = CAN_Write(PCAN_USBBUS1, &message);
    if (status != PCAN_ERROR_OK) {
        qDebug() << "Ошибка при отправке данных через CAN: " << status;
        return false;
    }

    return true;
}

bool MainWindow::receiveDataOverCAN(QByteArray &data)
{
    TPCANMsg message;
    TPCANTimestamp timestamp;

    TPCANStatus status = CAN_Read(PCAN_USBBUS1, &message, &timestamp);
    if (status != PCAN_ERROR_OK) {
        qDebug() << "Ошибка при получении данных через CAN: " << status;
        return false;
    }

    data = QByteArray((const char*)message.DATA, message.LEN);
    return true;
}

void MainWindow::setError(const QString &message)
{
    errorLabel->setText("Ошибка: " + message);
}
