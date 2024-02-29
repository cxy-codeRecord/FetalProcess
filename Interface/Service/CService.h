#ifndef CSERVICE_H
#define CSERVICE_H

#include <QObject>
#include "IService.h"
#include "../Common/Service/ServiceCommon.h"
class CService : public IService
{
public:
    CService(const QString& serviceName,const SERVICE_THREAD_ID& threadId,QObject* parent = nullptr);
    void startTimerHandle(int ms,QSharedPointer<CDataStreamBase> base);
    //void startTimerHandle(int timeout,function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)> func);
protected:
    void regiserService(const IService* service,const SERVICE_THREAD_ID& threadId);
};

#endif // CSERVICE_H
