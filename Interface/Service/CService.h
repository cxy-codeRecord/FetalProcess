#ifndef CSERVICE_H
#define CSERVICE_H

#include <QObject>
#include "IService.h"
#include "../Common/CDataStructs.h"
class CService : public IService
{
public:
    CService(const QString& serviceName,const SERVICE_THREAD_ID& threadId,QObject* parent = nullptr);
protected:
    void regiserService(const IService* service,const SERVICE_THREAD_ID& threadId);
};

#endif // CSERVICE_H
