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


