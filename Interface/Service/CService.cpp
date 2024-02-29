#include "CService.h"
#include "../Controller/CController.h"
CService::CService(const QString &serviceName,const SERVICE_THREAD_ID& threadId, QObject *parent):IService(serviceName,threadId,parent)
{
    regiserService(this,threadId);
}

void CService::startTimerHandle(int ms, QSharedPointer<CDataStreamBase> base)
{
    CController::getInstance()->startTimerHandle(ms,base);
}



void CService::regiserService(const IService *service, const SERVICE_THREAD_ID &threadId)
{
    CController::getInstance()->registerService(this,threadId);
}


