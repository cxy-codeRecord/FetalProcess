/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <CMainView/CMainView.h>
#include <CTGView/CTGView.h>
#include <ClientBar/CDigitalBar/CDigitalBar.h>
#include <ClientBar/CMenuBar/CMenuBar.h>
#include <ClientBar/CStatusBar/CStatusBar.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    CMainView *centralwidget;
    CMenuBar *menuBar;
    CDigitalBar *digitalBar;
    CTGView *ctgView;
    CStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 768);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"}"));
        centralwidget = new CMainView(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background-color:black;\n"
"}"));
        menuBar = new CMenuBar(centralwidget);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 131, 731));
        menuBar->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:#000000;\n"
"}"));
        digitalBar = new CDigitalBar(centralwidget);
        digitalBar->setObjectName("digitalBar");
        digitalBar->setGeometry(QRect(130, 0, 1151, 101));
        digitalBar->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:#1E1E1E;\n"
"}"));
        ctgView = new CTGView(centralwidget);
        ctgView->setObjectName("ctgView");
        ctgView->setGeometry(QRect(130, 100, 1151, 631));
        statusBar = new CStatusBar(centralwidget);
        statusBar->setObjectName("statusBar");
        statusBar->setGeometry(QRect(0, 720, 1280, 51));
        statusBar->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:#000000\n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
