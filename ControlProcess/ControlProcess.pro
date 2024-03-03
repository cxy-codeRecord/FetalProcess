#QT -= gui

#CONFIG += c++11 console
#CONFIG -= app_bundle
QT +=core network \
    widgets\
    gui
CONFIG += c++11
TARGET = ControlProcess
TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ##../Common/Net/CNetProtocol.cpp \
        ../Common/Net/ClientSockDataHandle.cpp \
        ../Common/Net/ControlSockDataHandle.cpp \
<<<<<<< HEAD
        CDemoFHRGenerate.cpp \
=======
>>>>>>> 11595e470d5ff74c05c1626b9aa15bb983d2a141
        ControlProcess.cpp \
        ../Common/Net/CNetMessage.cpp \
        ../Common/Net/CSockBuffer.cpp \
        ../Common/Net/CSockDataHandle.cpp \
        ControlProcessView.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ##../Common/Net/CNetProtocol.h \
<<<<<<< HEAD
    ../Common/CDataStructs.h \
    ../Common/Demo/DemoFetalHeartDataStructs.h \
    ../Common/MyCommon.h \
    ../Common/Net/ClientSockDataHandle.h \
    ../Common/Net/ControlSockDataHandle.h \
    CDemoFHRGenerate.h \
=======
    ../Common/Net/ClientSockDataHandle.h \
    ../Common/Net/ControlSockDataHandle.h \
>>>>>>> 11595e470d5ff74c05c1626b9aa15bb983d2a141
    ControlProcess.h\
    ../Common/Net/CNetCommon.h \
    ../Common/Net/CNetDataStructs.h \
    ../Common/Net/CNetMessage.h \
    ../Common/Net/CSockBuffer.h \
    ../Common/Net/CSockDataHandle.h \
    ControlProcessView.h

FORMS += \
    ControlProcessView.ui
