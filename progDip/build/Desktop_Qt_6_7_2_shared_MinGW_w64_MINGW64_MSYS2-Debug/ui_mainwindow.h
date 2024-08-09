/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *uploadButton;
    QPushButton *findButton;
    QPushButton *pushButton_3;
    QLabel *uploadPathLabel;
    QLabel *findPathLabel;
    QLabel *updateLabel;
    QGroupBox *groupBox;
    QRadioButton *hsCanRadioButton;
    QRadioButton *lsCanRadioButton;
    QRadioButton *fdCanRadioButton;
    QCheckBox *checkBox;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName("uploadButton");
        uploadButton->setGeometry(QRect(30, 70, 80, 18));
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName("findButton");
        findButton->setGeometry(QRect(130, 70, 80, 18));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(230, 70, 80, 18));
        uploadPathLabel = new QLabel(centralwidget);
        uploadPathLabel->setObjectName("uploadPathLabel");
        uploadPathLabel->setGeometry(QRect(50, 90, 37, 12));
        findPathLabel = new QLabel(centralwidget);
        findPathLabel->setObjectName("findPathLabel");
        findPathLabel->setGeometry(QRect(150, 90, 37, 12));
        updateLabel = new QLabel(centralwidget);
        updateLabel->setObjectName("updateLabel");
        updateLabel->setGeometry(QRect(250, 90, 37, 12));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 110, 120, 80));
        hsCanRadioButton = new QRadioButton(groupBox);
        hsCanRadioButton->setObjectName("hsCanRadioButton");
        hsCanRadioButton->setGeometry(QRect(10, 20, 91, 18));
        lsCanRadioButton = new QRadioButton(groupBox);
        lsCanRadioButton->setObjectName("lsCanRadioButton");
        lsCanRadioButton->setGeometry(QRect(10, 40, 81, 18));
        fdCanRadioButton = new QRadioButton(groupBox);
        fdCanRadioButton->setObjectName("fdCanRadioButton");
        fdCanRadioButton->setGeometry(QRect(10, 60, 81, 18));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(190, 120, 58, 18));
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(190, 160, 37, 12));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        uploadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\275\320\276\320\262\320\276\320\263\320\276 ", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\201\321\202\320\260\321\200\320\276\320\263\320\276", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        uploadPathLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        findPathLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        updateLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        hsCanRadioButton->setText(QCoreApplication::translate("MainWindow", "High-Speed CAN", nullptr));
        lsCanRadioButton->setText(QCoreApplication::translate("MainWindow", "Low-Speed CAN", nullptr));
        fdCanRadioButton->setText(QCoreApplication::translate("MainWindow", "CAN FD", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
