#ifndef CLIENTSOCKDATAHANDLE_H
#define CLIENTSOCKDATAHANDLE_H

#include <QObject>
#include "../Common/Net/CSockDataHandle.h"
class ClientSockDataHandle : public CSockDataHandle
{
    Q_OBJECT
public:
    explicit ClientSockDataHandle(QTcpSocket* tcpSocket,QObject *parent = nullptr);
    void handleNetMessage(QSharedPointer<CNetMessage> netMessage);
signals:
    void signalStartRecord();
    void signalPauseRecord();
    void signalEndRecord();

};

#endif // CLIENTSOCKDATAHANDLE_H
