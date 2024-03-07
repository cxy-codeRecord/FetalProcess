#include "ControlProcess.h"
#include "../Common/Net/ClientSockDataHandle.h"
#include <QDataStream>
#include <QIODevice>
ControlProcess::ControlProcess()
{


}


ControlProcess::~ControlProcess()
{
    quit();
}

void ControlProcess::initModule()
{
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()),Qt::QueuedConnection);
    QThread::start();
    start(8890);
}

bool ControlProcess::start(int port)
{
    bool ret = true;

    if(!m_server.isListening() )
    {
        ret = m_server.listen(QHostAddress("127.0.0.1"), port);
    }

    return ret;
}

void ControlProcess::stop()
{
    if( m_server.isListening() )
    {
        m_server.close();
    }
}

void ControlProcess::resetCTGData()
{
    m_demoFHRGenerate.resetDemoFetalHeartIndex();
}



void ControlProcess::onNewConnection()
{
    qDebug()<<"onNewConnection()"<<QThread::currentThreadId;
    QTcpSocket* tcp = m_server.nextPendingConnection();
//    QSharedPointer<CSockDataHandle> sockDataHandlePtr = QSharedPointer<ClientSockDataHandle>(new ClientSockDataHandle(tcp));
//    m_mapSockDataHandle.insert(tcp,sockDataHandlePtr);
    if(m_clientSockDataHandle.get())
    {
        m_clientSockDataHandle.reset();
    }
    m_clientSockDataHandle = QSharedPointer<ClientSockDataHandle>(new ClientSockDataHandle(tcp));
    connect(tcp, SIGNAL(connected()), this, SLOT(onConnected()),Qt::QueuedConnection);
    connect(tcp, SIGNAL(disconnected()), this, SLOT(onDisconnected()),Qt::QueuedConnection);
    connect(tcp, SIGNAL(readyRead()), this, SLOT(onDataReady()),Qt::QueuedConnection);
    connect(tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)),Qt::QueuedConnection);
    connect(m_clientSockDataHandle.get(),&CSockDataHandle::signalReadData,this,&ControlProcess::signalReadData,Qt::QueuedConnection);
    connect(m_clientSockDataHandle.get(),&ClientSockDataHandle::signalStartRecord,this,[=](){
        emit signalStartRecord();
    },Qt::QueuedConnection);
    connect(m_clientSockDataHandle.get(),&ClientSockDataHandle::signalPauseRecord,this,[=](){
        emit signalPauseRecord();
    },Qt::QueuedConnection);
    connect(m_clientSockDataHandle.get(),&ClientSockDataHandle::signalEndRecord,this,[=](){
        emit signalEndRecord();
    },Qt::QueuedConnection);


}

void ControlProcess::onConnected()
{

}

void ControlProcess::onDisconnected()
{

}

void ControlProcess::onDataReady()
{
   QTcpSocket* tcp = dynamic_cast<QTcpSocket*>(sender());
   if(tcp!=NULL&&m_clientSockDataHandle.get())
   {
       if(m_clientSockDataHandle.get()->getTcpSocket() == tcp)
       {
           m_clientSockDataHandle.get()->recvNetData();
       }
   }
}

void ControlProcess::onBytesWritten(qint64 bytes)
{

}

void ControlProcess::onUpLoadCTGData()
{
    CNetData data;
    data.cmd = CNetMessageType::UPLOAD_CTG_POINTS;
    data.data.resize(4*3);
    QDataStream stream(&data.data,QIODevice::ReadWrite);
    int demoFetalHeartOneData = m_demoFHRGenerate.getDemoFetalHeartOneData();
    int demoFetalHeartTwoData = m_demoFHRGenerate.getDemoFetalHeartTwoData();
    int demoFetalHeartThreeData = m_demoFHRGenerate.getDemoFetalHeartThreeData();
    stream<<int(demoFetalHeartOneData);
    stream<<int(demoFetalHeartTwoData);
    stream<<int(demoFetalHeartThreeData);
    m_clientSockDataHandle.get()->sendNetData(CNetMessageType::UPLOAD_CTG_POINTS,data.data);
}

