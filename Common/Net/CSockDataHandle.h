#ifndef CSOCKDATAHANDLE_H
#define CSOCKDATAHANDLE_H

#include <QObject>
#include "CSockBuffer.h"
#include <atomic>
#include <QTcpSocket>
#include "CNetDataStructs.h"
class CSockDataHandle : public QObject
{
    Q_OBJECT
protected:
    CSockBuffer m_ReadSockBuffer;
    CSockBuffer m_WriteSockBuffer;
    QTcpSocket* m_pTcpSocket = nullptr;
public:
    explicit CSockDataHandle(QTcpSocket* tcpSocket,QObject *parent = nullptr);
    ~CSockDataHandle();
    void sendNetData(int cmd,QByteArray& data);
    void recvNetData();
    QTcpSocket* getTcpSocket();
protected:
    void parseReadSockBufferData();
    void appendReadBufferData(const QByteArray& data);
    QSharedPointer<CNetMessage> readFirstNetMessage();
    QSharedPointer<CNetMessage> removeFirstNetMessage();
    int getNetMessageCount();
    virtual void handleNetMessage(QSharedPointer<CNetMessage> netMessage) = 0;
signals:
    void signalReadData(int type,QByteArray data,int dataIndex);
public slots:
};

#endif // CSOCKDATAHANDLE_H
