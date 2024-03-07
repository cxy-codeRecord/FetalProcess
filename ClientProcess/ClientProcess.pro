#-------------------------------------------------
#
# Project created by QtCreator 2024-01-01T10:47:22
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                        network

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
        ../Common/Net/CNetMessage.cpp \
        ../Common/Net/CSockBuffer.cpp \
        ../Common/Net/CSockDataHandle.cpp \
        ../Common/Net/ClientSockDataHandle.cpp \
        ../Common/Net/ControlSockDataHandle.cpp \
        ../CustomControls/CButton.cpp \
        ../CustomControls/CPageButton.cpp \
        ../Interface/Controller/CController.cpp \
        ../Interface/Controller/IController.cpp \
        ../Interface/Service/CService.cpp \
        ../Interface/Service/CServiceLoop.cpp \
        ../Interface/Service/CServiceManage.cpp \
        ../Interface/Service/CTimerServiceHandle.cpp \
        ../Interface/Service/IService.cpp \
        ../Interface/WidgetView/CWidgetView.cpp \
        ../Interface/WidgetView/CWidgetViewManage.cpp \
        ../Interface/WidgetView/IWidgetView.cpp \
        CDialog/CDialogManage/CDialogManage.cpp \
        CDialog/CHandleOnGoingStateDialog/CHandleOnGoingStateDialog.cpp \
        CDialog/CHandlePauseStateDialog/CHandlePauseStateDialog.cpp \
        CMainView/CMainView.cpp \
        CTGView/CBackGround.cpp \
        CTGView/CCPAxisTickerTimer.cpp \
        CTGView/CGrid.cpp \
        CTGView/CTGState.cpp \
        CTGView/CTGView.cpp \
        CTGView/qcustomplot.cpp \
        CViewHelp/CViewHelp.cpp \
        ClientBar/CDigitalBar/CDigitalBar.cpp \
        ClientBar/CMenuBar/CMenuBar.cpp \
        CService/CNetService/CNetService.cpp\
        CService/CServiceGenerate/CServiceGenerate.cpp \
        ClientBar/CStatusBar/CStatusBar.cpp \
        form.cpp \
        main.cpp

HEADERS += \
        ../Common/CDataStructs.h \
        ../Common/Dialog/DialogCommon.h \
        ../Common/Net/CNetCommon.h \
        ../Common/Net/CNetDataStructs.h \
        ../Common/Net/CNetMessage.h \
        ../Common/Net/CSockBuffer.h \
        ../Common/Net/CSockDataHandle.h \
        ../Common/MyCommon.h \
        ../Common/Net/ClientSockDataHandle.h \
        ../Common/Net/ControlSockDataHandle.h \
        ../Common/Service/ServiceCommon.h \
        ../Common/View/ViewCommon.h \
        ../CustomControls/CButton.h \
        ../CustomControls/CPageButton.h \
        ../Interface/Controller/CController.h \
        ../Interface/Controller/IController.h \
        ../Interface/Service/CService.h \
        ../Interface/Service/CServiceLoop.h \
        ../Interface/Service/CServiceManage.h \
        ../Interface/Service/CTimerServiceHandle.h \
        ../Interface/Service/IService.h \
        ../Interface/WidgetView/CWidgetView.h \
        ../Interface/WidgetView/CWidgetViewManage.h \
        ../Interface/WidgetView/IWidgetView.h \
        CDialog/CDialogManage/CDialogManage.h \
        CDialog/CHandleOnGoingStateDialog/CHandleOnGoingStateDialog.h \
        CDialog/CHandlePauseStateDialog/CHandlePauseStateDialog.h \
        CMainView/CMainView.h \
        CService/CNetService/CNetService.h \
        CTGView/CBackGround.h \
        CTGView/CCPAxisTickerTimer.h \
        CTGView/CGrid.h \
        CTGView/CTGState.h \
        CTGView/CTGView.h \
        CTGView/qcustomplot.h \
        CViewHelp/CViewHelp.h \
        ClientBar/CDigitalBar/CDigitalBar.h \
        ClientBar/CMenuBar/CMenuBar.h \
        CService/CServiceGenerate/CServiceGenerate.h \
        ClientBar/CStatusBar/CStatusBar.h \
        form.h

FORMS += \
    CDialog/CDialogManage/CDialogManage.ui \
    CDialog/CHandleOnGoingStateDialog/CHandleOnGoingStateDialog.ui \
    CDialog/CHandlePauseStateDialog/CHandlePauseStateDialog.ui \
    ClientBar/CDigitalBar/CDigitalBar.ui \
    ClientBar/CMenuBar/CMenuBar.ui \
    ClientBar/CStatusBar/CStatusBar.ui \
    form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/resource.qrc
