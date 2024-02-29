#ifndef CONTROLPROCESS_H
#define CONTROLPROCESS_H

#include <QThread>
#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTimer>
#include "../Common/Net/CSockDataHandle.h"
#include "../Common/Net/ClientSockDataHandle.h"
class ControlProcess : public QThread
{
    Q_OBJECT
    QTcpServer m_server;
    QSharedPointer<ClientSockDataHandle> m_clientSockDataHandle;
    //QMap<QTcpSocket*, QSharedPointer<CSockDataHandle>> m_mapSockDataHandle;
    //QTimer m_timer;
    //QTimer m_uploadCTGDataTimer;
    QSharedPointer<QTimer> m_uploadCTGDataTimer;
public:
     ControlProcess();
    ~ControlProcess();
    void initModule();
    bool start(int port);
    void stop();
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
};

#endif // CONTROLPROCESS_H
