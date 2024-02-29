#include "ClientSockDataHandle.h"
#include <QDebug>
#include "../Common/Net/CNetCommon.h"
ClientSockDataHandle::ClientSockDataHandle(QTcpSocket *tcpSocket, QObject *parent) : CSockDataHandle(tcpSocket,parent)
{

}

void ClientSockDataHandle::handleNetMessage(QSharedPointer<CNetMessage> netMessage)
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
//    emit signalReadData(type,data,index);
//    QByteArray ba;
//    this->sendNetData((int)CMD_FETAL_HEART_RATE,ba);
    if(netMessage.isNull())return;
    CNetMessageType_T type = (CNetMessageType_T)netMessage->getDataType();
    switch (type)
    {
    case CNetMessageType_T::START_RECORD:
    {
        emit signalStartRecord();
        break;
    }
    case CNetMessageType_T::PAUSE_RECORD:
    {
        emit signalPauseRecord();
        break;
    }
    case CNetMessageType_T::END_RECORD:
    {
        emit signalEndRecord();
        break;
    }
    }
}
