#ifndef CSERVICEGENERATE_H
#define CSERVICEGENERATE_H
#include <QObject>
#include "../CNetService/CNetService.h"
#include "../Common/MyCommon.h"
#include "../Interface/Controller/CController.h"
class CServiceGenerator:public QObject
{
    Q_OBJECT
    SINGLETON(CServiceGenerator)
public:
    CNetService* netService = nullptr;
public:
    CServiceGenerator();
    void initModule();

};

#endif
