#include "ControlSockDataHandle.h"
#include <QDataStream>
#include "../Common/Service/ServiceCommon.h"
#include "../Common/MyCommon.h"
ControlSockDataHandle::ControlSockDataHandle(QTcpSocket *tcpSocket, QObject *parent) : CSockDataHandle(tcpSocket,parent)
{

}

void ControlSockDataHandle::handleNetMessage(QSharedPointer<CNetMessage> netMessage)
{
//    QByteArray data = netMessage->getData();
//    int type  = netMessage->getDataType();
//    int index = netMessage->getDataIndex();
//    QString strType = QString("type:")+ QString().setNum(type);
//    QString strData;
//    QString strIndex;
//    strData.append("data:");
//    for(int i=0;i<data.length();i++)
//    {
//        unsigned char c = (unsigned char)data[i];
//        strData.append("0x");
//        strData.append(QString().setNum(c,16));
//        strData.append(" ");
//    }
//    strIndex = QString("dataIndex:") + QString().setNum(index);
//    qDebug()<<strType;
//    qDebug()<<strData;
//    qDebug()<<strIndex;
    //emit signalReadData(type,data,index);
    CNetMessageType_T type = (CNetMessageType_T)netMessage->getDataType();
    switch (type)
    {
    case CNetMessageType_T::UPLOAD_CTG_POINTS:
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
