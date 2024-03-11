#include "CNetService.h"
#include "../Common/View/ViewCommon.h"
bool CNetService::connectTo(QString ip, int port)
{
    m_controlSocket->connectToHost(ip, port);
    return m_controlSocket->waitForConnected(80000);
}

QSharedPointer<CDataStreamBase> CNetService::sendNetData(QSharedPointer<CDataStreamBase> dataStream)
{
//    if(m_controlSocket.isNull())
//    {
//        m_controlSocket = QSharedPointer<QTcpSocket>(new QTcpSocket);
//        m_controlSockDataHandle = QSharedPointer<ControlSockDataHandle>(new ControlSockDataHandle(m_controlSocket.get()));
//        connect(m_controlSockDataHandle.get(),&ControlSockDataHandle::signalSendResponse,this,&CNetService::signalSendResponse,Qt::QueuedConnection);
//        connectTo("127.0.0.1",8890);
//    }
    CDataStream<CNetData>* netData = dataStream->toDataStream<CDataStream<CNetData>>();
    QSharedPointer<CDataStream<bool>> ret = QSharedPointer<CDataStream<bool>>(new CDataStream<bool>);
    ret->data = false;
    if(netData)
    {
        CNetData& dataStruct = netData->data;
        CNetMessageType& cmd = dataStruct.cmd;
        QByteArray& data = dataStruct.data;
        m_controlSockDataHandle->sendNetData(cmd,data);
        ret->data = true;
    }
    return ret;
}

QSharedPointer<CDataStreamBase> CNetService::recvNetData(QSharedPointer<CDataStreamBase> dataStream)
{
    QSharedPointer<CDataStreamBase> ret;
    if(m_controlSocket->waitForReadyRead(10))
    {
        m_controlSockDataHandle->recvNetData();
    }
    return ret;
}

QSharedPointer<CDataStreamBase> CNetService::controllerRecord(QSharedPointer<CDataStreamBase> dataStream)
{
    CDataStream<CRecordCmd>* cmd = dataStream->toDataStream<CDataStream<CRecordCmd>>();
    QSharedPointer<CDataStream<CRecordState>> state = QSharedPointer<CDataStream<CRecordState>>(new CDataStream<CRecordState>());
    QSharedPointer<CDataStream<CNetData>> netData = QSharedPointer<CDataStream<CNetData>>(new CDataStream<CNetData>);
    state->data = CRecordState::ERROR_STATE;
    if(cmd)
    {
        switch (cmd->data)
        {
        case CRecordCmd::START_RECORD:
        {
            netData->data.cmd = CNetMessageType::START_RECORD;
            QSharedPointer<CDataStreamBase> ret = sendNetData(netData);
            CDataStream<bool>* ptr =  ret->toDataStream<CDataStream<bool>>();
            if(ptr->data)
            {
                state->data = CRecordState::ONGOING_STATE;
            }
            break;
        }
        case CRecordCmd::PAUSE_RECORD:
        {
            netData->data.cmd = CNetMessageType::PAUSE_RECORD;
            QSharedPointer<CDataStreamBase> ret = sendNetData(netData);
            CDataStream<bool>* ptr =  ret->toDataStream<CDataStream<bool>>();
            if(ptr->data)
            {
                state->data = CRecordState::PAUSE_STATE;
            }
            break;
        }
        case CRecordCmd::END_RECORD:
        {
            netData->data.cmd = CNetMessageType::END_RECORD;
            QSharedPointer<CDataStreamBase> ret = sendNetData(netData);
            CDataStream<bool>* ptr =  ret->toDataStream<CDataStream<bool>>();
            if(ptr->data)
            {
                state->data = CRecordState::IDLE_STATE;
            }
            break;
        }
        }
    }
    return state;
}

void CNetService::serviceInit()
{
    m_controlSocket = QSharedPointer<QTcpSocket>(new QTcpSocket);
    m_controlSockDataHandle = QSharedPointer<ControlSockDataHandle>(new ControlSockDataHandle(m_controlSocket.get()));
    connect(m_controlSockDataHandle.get(),&ControlSockDataHandle::signalSendResponse,this,&CNetService::signalSendResponse,Qt::QueuedConnection);
    connectTo("127.0.0.1",NET_PORT);
}

void CNetService::serviceExit()
{
    m_controlSocket->close();
    m_controlSockDataHandle.reset();
    m_controlSocket.reset();
}

void CNetService::initModule()
{
   registerServiceInitHandleFunc(bind(&CNetService::serviceInit,this));
   registerServiceExitHandleFunc(bind(&CNetService::serviceExit,this));
   registerServiceHandleFunc(SERVICE_FUNC_RECV_NETDATA,bind(&CNetService::recvNetData,this,std::placeholders::_1));
   registerServiceHandleFunc(SERVICE_FUNC_CONTROLLER_RECORD,bind(&CNetService::controllerRecord,this,std::placeholders::_1));
   QSharedPointer<CDataStreamBase> data = QSharedPointer<CDataStreamBase>(new CDataStreamBase);
   data->serviceName = CNETSERVICE_NAME;
   data->handleFuncName = SERVICE_FUNC_RECV_NETDATA;
   startTimerHandle(200,data);
}


CNetService::~CNetService()
{


}

CNetService::CNetService():CService(CNETSERVICE_NAME,SERVICE_THREAD_ID::ServiceThread0)
{

}
