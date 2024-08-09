/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *uploadLabel;
    QLabel *findLabel;
    QLabel *updateLabel;
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
        uploadLabel = new QLabel(centralwidget);
        uploadLabel->setObjectName("uploadLabel");
        uploadLabel->setGeometry(QRect(50, 90, 37, 12));
        findLabel = new QLabel(centralwidget);
        findLabel->setObjectName("findLabel");
        findLabel->setGeometry(QRect(150, 90, 37, 12));
        updateLabel = new QLabel(centralwidget);
        updateLabel->setObjectName("updateLabel");
        updateLabel->setGeometry(QRect(250, 90, 37, 12));
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
        uploadButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        uploadLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        findLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        updateLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
