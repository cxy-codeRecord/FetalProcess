#ifndef CNETPROTOCOL_H
#define CNETPROTOCOL_H

#include <QObject>
#include <QByteArray>
#include <QTcpSocket>
#include "../Common/Net/CSockDataHandle.h"
class CNetProtocol : public QObject
{
    Q_OBJECT
public:
    explicit CNetProtocol(QTcpSocket* tcpSocket,QObject *parent = nullptr);
    void sendNetData(int cmd,QByteArray data);
    void readNetData();
protected:
    QTcpSocket* m_pTcpSocket = nullptr;
    CSockDataHandle m_sockDataHandle;
signals:

};

#endif // CNETPROTOCOL_H
