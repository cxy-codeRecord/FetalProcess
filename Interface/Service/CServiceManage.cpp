#include "CServiceManage.h"
#include <QDebug>
CServiceManage::CServiceManage(QObject *parent) : QObject(parent)
{
    m_CTimerServiceHandle.initModule();
    connect(&m_CTimerServiceHandle,&CTimerServiceHandle::siganlRequestService,this,&CServiceManage::onRequestService,Qt::QueuedConnection);
}

void CServiceManage::registerService(IService *service, SERVICE_THREAD_ID serviceThreadId)
{
    unique_lock<mutex> lock(m_mutex);
    if(m_mapServiceLoop.contains(serviceThreadId))
    {
       CServiceLoop* serviceLoop = m_mapServiceLoop[serviceThreadId];
       const QString serviceName = service->getServiceName();
       serviceLoop->addService(serviceName,service);
       connect(service,&IService::signalSendResponse,this,[=](const QString funcName,const QSharedPointer<CDataStreamBase> responsePack){
           emit signalSendResponse(funcName,responsePack);
       },Qt::QueuedConnection);
    }
}

void CServiceManage::initModule()
{
    unique_lock<mutex> lock(m_mutex);
    initServiceLoop();

}

void CServiceManage::initServiceModule()
{
   unique_lock<mutex> lock(m_mutex);
   auto it = m_mapServiceLoop.begin();
   while(it!=m_mapServiceLoop.end())
   {
       CServiceLoop* loop = it.value();
       loop->initService();
       it++;
   }
}

CServiceManage::~CServiceManage()
{
    freeServiceLoop();
}

void CServiceManage::startTimerHanle(int ms,QSharedPointer<CDataStreamBase> base)
{
    m_CTimerServiceHandle.startTimerHandle(ms,base);
}

void CServiceManage::onRequestService(QSharedPointer<CDataStreamBase> pack)
{
    unique_lock<mutex> lock(m_mutex);
    auto it = m_mapServiceLoop.begin();
    while(it!=m_mapServiceLoop.end())
    {
        CServiceLoop* serviceLoop = it.value();
        bool ret = serviceLoop->containService(pack->serviceName);
        if(ret)
        {
           serviceLoop->requestService(pack);
           break;
        }
        it++;
    }
}

void CServiceManage::initServiceLoop()
{
    unique_lock<mutex> lock(m_mutex);
    for(int i=0;i<SERVICE_THREAD_COUNT;i++)
    {
        CServiceLoop* serviceLoop = new CServiceLoop();
        connect(serviceLoop,&CServiceLoop::signalSendResponse,this,&CServiceManage::signalSendResponse,Qt::QueuedConnection);
        m_mapServiceLoop[(SERVICE_THREAD_ID)i] = serviceLoop;
        serviceLoop->initModule();
    }
}

void CServiceManage::freeServiceLoop()
{
    unique_lock<mutex> lock(m_mutex);
    auto it = m_mapServiceLoop.begin();
    while (it!=m_mapServiceLoop.end()) {
        CServiceLoop* serviceLoop = it.value();
        it++;
        serviceLoop->exitMoudle();
    }
}

