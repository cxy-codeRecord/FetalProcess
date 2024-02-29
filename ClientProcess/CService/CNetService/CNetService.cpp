#include "CNetService.h"
#include "../Common/View/ViewCommon.h"
bool CNetService::connectTo(QString ip, int port)
{
    m_controlSocket->connectToHost(ip, port);
    return m_controlSocket->waitForConnected();
}

QSharedPointer<CDataStreamBase> CNetService::sendNetData(QSharedPointer<CDataStreamBase> dataStream)
{
    if(m_controlSocket.isNull())
    {
        m_controlSocket = QSharedPointer<QTcpSocket>(new QTcpSocket);
        m_controlSockDataHandle = QSharedPointer<ControlSockDataHandle>(new ControlSockDataHandle(m_controlSocket.get()));
        connect(m_controlSockDataHandle.get(),&ControlSockDataHandle::signalSendResponse,this,&CNetService::signalSendResponse,Qt::QueuedConnection);
        connectTo("127.0.0.1",8890);
    }
    CDataStream<CNetData>* netData = dataStream->toDataStream<CDataStream<CNetData>>();
    QSharedPointer<CDataStreamBase> ret;
    if(netData)
    {
        CNetData& dataStruct = netData->data;
        CNetMessageType_T& cmd = dataStruct.cmd;
        QByteArray& data = dataStruct.data;
        m_controlSockDataHandle->sendNetData(cmd,data);
    }
    return ret;
}

QSharedPointer<CDataStreamBase> CNetService::recvNetData(QSharedPointer<CDataStreamBase> dataStream)
{
    QSharedPointer<CDataStreamBase> ret;
    if(m_controlSocket.isNull())
    {
        m_controlSocket = QSharedPointer<QTcpSocket>(new QTcpSocket);
        m_controlSockDataHandle = QSharedPointer<ControlSockDataHandle>(new ControlSockDataHandle(m_controlSocket.get()));
        connect(m_controlSockDataHandle.get(),&ControlSockDataHandle::signalSendResponse,this,&CNetService::signalSendResponse,Qt::QueuedConnection);
        connectTo("127.0.0.1",8890);
    }
    if(m_controlSocket->waitForReadyRead(10))
    {
        m_controlSockDataHandle->recvNetData();
    }
    return ret;
}

QSharedPointer<CDataStreamBase> CNetService::startRecord(QSharedPointer<CDataStreamBase> dataStream)
{
    return sendNetData(dataStream);
}

void CNetService::initModule()
{
   registerServiceHandleFunc(SERVICE_FUNC_START_RECORD,bind(&CNetService::startRecord,this,std::placeholders::_1));
   registerServiceHandleFunc(SERVICE_FUNC_RECV_NETDATA,bind(&CNetService::recvNetData,this,std::placeholders::_1));
   QSharedPointer<CDataStreamBase> data = QSharedPointer<CDataStreamBase>(new CDataStreamBase);
   data->serviceName = CNETSERVICE_NAME;
   data->handleFuncName = SERVICE_FUNC_RECV_NETDATA;
   startTimerHandle(200,data);


}

void CNetService::exitModule()
{
    m_controlSocket->close();
    m_controlSockDataHandle.reset();
    m_controlSocket.reset();
}

CNetService::~CNetService()
{


}

CNetService::CNetService():CService(CNETSERVICE_NAME,SERVICE_THREAD_ID::ServiceThread0)
{

}
