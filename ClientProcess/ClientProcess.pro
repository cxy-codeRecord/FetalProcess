#-------------------------------------------------
#
# Project created by QtCreator 2024-01-01T10:47:22
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientProcess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ../CustomControls/CButton.cpp \
        ../CustomControls/CPageButton.cpp \
        ../Interface/Controller/CController.cpp \
        ../Interface/Controller/IController.cpp \
        ../Interface/Service/CService.cpp \
        ../Interface/Service/CServiceLoop.cpp \
        ../Interface/Service/CServiceManage.cpp \
        ../Interface/Service/IService.cpp \
        ../Interface/WidgetView/CWidgetView.cpp \
        ../Interface/WidgetView/CWidgetViewManage.cpp \
        ../Interface/WidgetView/IWidgetView.cpp \
        CMainView/CMainView.cpp \
        CTGView/CBackGround.cpp \
        CTGView/CCPAxisTickerTimer.cpp \
        CTGView/CGrid.cpp \
        CTGView/CTGState.cpp \
        CTGView/CTGView.cpp \
        CTGView/qcustomplot.cpp \
        ClientBar/CDigitalBar/CDigitalBar.cpp \
        ClientBar/CMenuBar/CMenuBar.cpp \
        ClientBar/CStatusBar/CStatusBar.cpp \
        form.cpp \
        main.cpp

HEADERS += \
        ../Common/CDataStructs.h \
        ../Common/MyCommon.h \
        ../CustomControls/CButton.h \
        ../CustomControls/CPageButton.h \
        ../Interface/Controller/CController.h \
        ../Interface/Controller/IController.h \
        ../Interface/Service/CService.h \
        ../Interface/Service/CServiceLoop.h \
        ../Interface/Service/CServiceManage.h \
        ../Interface/Service/IService.h \
        ../Interface/WidgetView/CWidgetView.h \
        ../Interface/WidgetView/CWidgetViewManage.h \
        ../Interface/WidgetView/IWidgetView.h \
        CMainView/CMainView.h \
        CTGView/CBackGround.h \
        CTGView/CCPAxisTickerTimer.h \
        CTGView/CGrid.h \
        CTGView/CTGState.h \
        CTGView/CTGView.h \
        CTGView/qcustomplot.h \
        ClientBar/CDigitalBar/CDigitalBar.h \
        ClientBar/CMenuBar/CMenuBar.h \
        ClientBar/CStatusBar/CStatusBar.h \
        form.h

FORMS += \
    form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/resource.qrc