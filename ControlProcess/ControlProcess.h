#ifndef CONTROLPROCESS_H
#define CONTROLPROCESS_H

#include <QThread>
#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTimer>
#include "../Common/Net/CSockDataHandle.h"
#include "../Common/Net/ClientSockDataHandle.h"
<<<<<<< HEAD
#include "CDemoFHRGenerate.h"
=======
>>>>>>> 11595e470d5ff74c05c1626b9aa15bb983d2a141
class ControlProcess : public QThread
{
    Q_OBJECT
    QTcpServer m_server;
    QSharedPointer<ClientSockDataHandle> m_clientSockDataHandle;
<<<<<<< HEAD
    QSharedPointer<QTimer> m_uploadCTGDataTimer;
    CDemoFHRGenerate m_demoFHRGenerate;
=======
    //QMap<QTcpSocket*, QSharedPointer<CSockDataHandle>> m_mapSockDataHandle;
    //QTimer m_timer;
    //QTimer m_uploadCTGDataTimer;
    QSharedPointer<QTimer> m_uploadCTGDataTimer;
>>>>>>> 11595e470d5ff74c05c1626b9aa15bb983d2a141
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
