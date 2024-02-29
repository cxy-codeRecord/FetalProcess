#ifndef CONTROLSOCKDATAHANDLE_H
#define CONTROLSOCKDATAHANDLE_H

#include <QObject>
#include "CSockDataHandle.h"
#include <QTcpSocket>
#include "../Common/CDataStructs.h"
class ControlSockDataHandle : public CSockDataHandle
{
    Q_OBJECT
public:
    explicit ControlSockDataHandle(QTcpSocket* tcpSocket,QObject *parent = nullptr);
    void handleNetMessage(QSharedPointer<CNetMessage> netMessage);
signals:
    void signalSendResponse(const QString funcName,const QSharedPointer<CDataStreamBase> responsePack);

};

#endif // CONTROLSOCKDATAHANDLE_H
