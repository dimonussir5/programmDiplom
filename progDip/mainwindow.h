#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QByteArray>
#include <windows.h>  // Не забудьте это

#include "PCANBasic.h"  // Убедитесь, что файл находится в вашем проекте

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUploadAlgorithmClicked();
    void onFindOldAlgorithmClicked();
    void onUpdateAlgorithmClicked();
    void onRadioButtonToggled();
    void onCheckBoxStateChanged(int state);

private:
    QPushButton *uploadButton;
    QPushButton *findButton;
    QPushButton *updateButton;
    QRadioButton *hsCanRadioButton;
    QRadioButton *lsCanRadioButton;
    QRadioButton *fdCanRadioButton;
    QCheckBox *autoDetectCheckBox;
    QLabel *uploadPathLabel;
    QLabel *findPathLabel;
    QLabel *errorLabel;

    QByteArray algorithmData;  // Переменная для хранения загруженного алгоритма

    bool sendDataOverCAN(const QByteArray &data);
    bool receiveDataOverCAN(QByteArray &data);
    void detectCanType();
    void setError(const QString &message);
};

#endif // MAINWINDOW_H
