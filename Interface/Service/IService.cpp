#include "IService.h"
#include <QDebug>
QString IService::getServiceName()
{
    return m_serviceName;
}

SERVICE_THREAD_ID IService::getServiceThreadId()
{
    return m_serviceThreadId;
}


IService::IService(const QString& serviceName,const SERVICE_THREAD_ID& threadId,QObject *parent)
  :QObject(parent),
  m_serviceName(serviceName),
  m_serviceThreadId(threadId)
{

}

IService::~IService()
{

}

void IService::registerServiceHandleFunc(const QString&& funcName, function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>func)
{
    m_mapServiceHandleFunc[funcName] = func;
}

bool IService::getServiceHandleFunc(const QString &funcName, function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>&func)
{
    if(m_mapServiceHandleFunc.contains(funcName))
    {
        auto serviceFunc = m_mapServiceHandleFunc[funcName];
        func = serviceFunc;
        return true;
    }
    return false;
}

function<void(void)> IService::getServiceInitHandleFunc()
{
    return m_serviceInitFunc;
}

function<void(void)> IService::getServiceExitHandleFunc()
{
    return m_serviceExitFunc;
}

void IService::registerServiceInitHandleFunc(function<void ()> func)
{
    m_serviceInitFunc = func;
}

void IService::registerServiceExitHandleFunc(function<void ()> func)
{
    m_serviceExitFunc = func;
}


