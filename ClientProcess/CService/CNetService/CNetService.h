#ifndef CNETSERVICE_H
#define CNETSERVICE_H
#include "../Interface/Service/CService.h"
#include "../Common/Net/CNetCommon.h"
#include "../Common/Net/CNetDataStructs.h"
#include "../Common/Net/CNetMessage.h"
#include "../Common/Net/CSockBuffer.h"
#include "../Common/Net/CSockDataHandle.h"
#include "../Common/CDataStructs.h"
#include "../Common/Net/ControlSockDataHandle.h"
#include <QTcpSocket>
#include <QSharedPointer>
class CNetService:public CService
{
    Q_OBJECT
protected:
    QSharedPointer<ControlSockDataHandle> m_controlSockDataHandle;
    QSharedPointer<QTcpSocket> m_controlSocket;
    bool connectTo(QString ip, int port);
    QSharedPointer<CDataStreamBase> sendNetData(QSharedPointer<CDataStreamBase> dataStream);
    QSharedPointer<CDataStreamBase> recvNetData(QSharedPointer<CDataStreamBase> dataStream);
    QSharedPointer<CDataStreamBase> controllerRecord(QSharedPointer<CDataStreamBase> dataStream);
    void serviceInit();
    void serviceExit();
public:
    CNetService();
    void initModule();
    //void exitModule();
    virtual ~CNetService();



};

#endif
