#include "CServiceLoop.h"
#include "../Common/MyCommon.h"
#include <QSharedPointer>
CServiceLoop::CServiceLoop(QObject *parent):
   QThread (parent),
   m_Running(false)
{

}

void CServiceLoop::initModule()
{
    startRunning();
}

void CServiceLoop::exitMoudle()
{
    stopRunning();
    wait();
    quit();
}

void CServiceLoop::startRunning()
{
    m_Running = true;
    start();
}

void CServiceLoop::stopRunning()
{
    m_Running = false;
    m_condition.notify_all();

}

void CServiceLoop::initServiceModule()
{
    unique_lock<mutex> lock(m_mutex);
    auto it = m_mapService.begin();
    while(it!=m_mapService.end())
    {
        qDebug()<<"Service "<<it.key()<<" initModule begin";
        it.value()->initModule();
        qDebug()<<"Service "<<it.key()<<" initModule end";
        it++;
    }
}

void CServiceLoop::run()
{
    serviceInit();
    serviceRun();
    serviceExit();
}

void CServiceLoop::addService(const QString &serviceName, IService *service)
{
    unique_lock<mutex> lock(m_mutex);
    m_mapService[serviceName] = service;
}


bool CServiceLoop::containService(const QString &serviceName)
{
    unique_lock<mutex> lock(m_mutex);
    bool ret = m_mapService.contains(serviceName);
    return ret;
}


void CServiceLoop::requestService(const QSharedPointer<CDataStreamBase> pack)
{
    unique_lock<mutex> lock(m_mutex);
    m_ServicePacks.push_back(pack);
    m_condition.notify_all();
}

void CServiceLoop::serviceInit()
{
    unique_lock<mutex> lock(m_mutex);
    auto it = m_mapService.begin();
    while(it!=m_mapService.end())
    {
        function<void(void)> initFunc = it.value()->getServiceInitHandleFunc();
        qDebug()<<"serviceInit "<<it.key()<<" begin";
        if(initFunc)
        {
            initFunc();
        }
        qDebug()<<"serviceInit "<<it.key()<<" end";
        it++;
    }
}

void CServiceLoop::serviceExit()
{
    unique_lock<mutex> lock(m_mutex);
    auto it = m_mapService.begin();
    while(it!=m_mapService.end())
    {
        function<void(void)> exitFunc = it.value()->getServiceExitHandleFunc();
        qDebug()<<"serviceExit "<<it.key()<<" begin";
        if(exitFunc)
        {
            exitFunc();
        }
        qDebug()<<"serviceExit "<<it.key()<<" begin";
        delete(it.value());
        it++;
    }
}

void CServiceLoop::serviceRun()
{
    while(m_Running)
    {
        unique_lock<mutex> lock(m_mutex);
        m_condition.wait(lock,[this]{
            return ((m_ServicePacks.length()>0)||(!m_Running));
        });
        if(m_ServicePacks.length()>0)
        {
           QSharedPointer<CDataStreamBase> requestPack =  m_ServicePacks.head();
           m_ServicePacks.pop_front();
           lock.unlock();
           QString&  serviceName = requestPack->serviceName;
           QString&  serviceFuncName = requestPack->handleFuncName;
           IService* service = m_mapService[serviceName];
           function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>handleFunc = nullptr;
           if(m_mapService.contains(serviceName))
           {
               bool ret = service->getServiceHandleFunc(serviceFuncName,handleFunc);
               if(!ret)
               {
                 continue;
               }
           }
           if(handleFunc)
           {
             QSharedPointer<CDataStreamBase> responsePack = handleFunc(requestPack);
             emit signalSendResponse(serviceFuncName + RECVHANDLE_FUNC_SUFFIX,responsePack);
           }
        }
    }
}

CServiceLoop::~CServiceLoop()
{
    stopRunning();
    wait();
    quit();
}
