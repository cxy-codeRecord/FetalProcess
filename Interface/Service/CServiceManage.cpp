#include "CServiceManage.h"
#include <QDebug>
CServiceManage::CServiceManage(QObject *parent) : QObject(parent)
{

}

void CServiceManage::registerService(IService *service, SERVICE_THREAD_ID serviceThreadId)
{
    unique_lock<mutex> lock(m_mutex);
    if(m_mapServiceLoop.contains(serviceThreadId))
    {
       CServiceLoop* serviceLoop = m_mapServiceLoop[serviceThreadId];
       const QString serviceName = service->getServiceName();
//       connect(service,&IService::signal_RequestService,this,&CServiceManage::slot_RequestService,Qt::QueuedConnection);
       serviceLoop->addService(serviceName,service);
    }
}

void CServiceManage::initModule()
{
    initServiceLoop();
}


CServiceManage::~CServiceManage()
{
    freeServiceLoop();
}


void CServiceManage::slot_RequestService(const QSharedPointer<CDataStreamBase>& pack)
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
        connect(serviceLoop,&CServiceLoop::signal_SendResponse,this,&CServiceManage::signal_SendResponse);
        m_mapServiceLoop[(SERVICE_THREAD_ID)i] = serviceLoop;
        serviceLoop->initModule();
    }
}

void CServiceManage::freeServiceLoop()
{
    auto it = m_mapServiceLoop.begin();
    while (it!=m_mapServiceLoop.end()) {
        CServiceLoop* serviceLoop = it.value();
        it++;
        serviceLoop->deleteLater();
    }
}

