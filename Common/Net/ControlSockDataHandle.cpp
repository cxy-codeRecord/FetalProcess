#include "ControlSockDataHandle.h"
#include <QDataStream>
#include "../Common/Service/ServiceCommon.h"
#include "../Common/MyCommon.h"
ControlSockDataHandle::ControlSockDataHandle(QTcpSocket *tcpSocket, QObject *parent) : CSockDataHandle(tcpSocket,parent)
{

}

void ControlSockDataHandle::handleNetMessage(QSharedPointer<CNetMessage> netMessage)
{
    CNetMessageType type = (CNetMessageType)netMessage->getDataType();
    switch (type)
    {
    case CNetMessageType::UPLOAD_CTG_POINTS:
    {
        QByteArray data = netMessage->getData();
        QDataStream stream(data);
        int fetalHeartOne = 0;
        int fetalHeartTwo = 0;
        int fetalHeartThree = 0;
        QSharedPointer<CDataStream<CFetalHeartData>> fetalHeartData = QSharedPointer<CDataStream<CFetalHeartData>>(new CDataStream<CFetalHeartData>());
        stream>>fetalHeartData->data.fetalHeartOne;
        stream>>fetalHeartData->data.fetalHeartTwo;
        stream>>fetalHeartData->data.fetalHeartThree;
        emit signalSendResponse(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_GET_FETAL_HEART_DATA),fetalHeartData);
        break;
    }
    }
}
