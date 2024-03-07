#ifndef CONTROLPROCESS_H
#define CONTROLPROCESS_H

#include <QThread>
#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTimer>
#include "../Common/Net/CSockDataHandle.h"
#include "../Common/Net/ClientSockDataHandle.h"
#include "CDemoFHRGenerate.h"
class ControlProcess : public QThread
{
    Q_OBJECT
    QTcpServer m_server;
    QSharedPointer<ClientSockDataHandle> m_clientSockDataHandle;
    QSharedPointer<QTimer> m_uploadCTGDataTimer;
    CDemoFHRGenerate m_demoFHRGenerate;
public:
     ControlProcess();
    ~ControlProcess();
    void initModule();
    bool start(int port);
    void stop();
    void resetCTGData();
protected slots:
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onDataReady();
    void onBytesWritten(qint64 bytes);
public slots:
    void onUpLoadCTGData();
signals:
    void signalReadData(int type,QByteArray data,int dataIndex);
    void signalStartRecord();
    void signalPauseRecord();
    void signalEndRecord();
};

#endif // CONTROLPROCESS_H
