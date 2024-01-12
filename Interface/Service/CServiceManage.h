#ifndef CSERVICEMANAGE_H
#define CSERVICEMANAGE_H
#include <QObject>
#include <QMap>
#include "IService.h"
#include <mutex>
#include <QQueue>
#include <QThread>
#include <condition_variable>
#include <atomic>
#include "../Common/CDataStructs.h"
#include "../Common/MyCommon.h"
#include "CServiceLoop.h"
#include <QList>
using namespace std;
class CServiceManage : public QObject
{
    Q_OBJECT
    SINGLETON(CServiceManage)
public:
    explicit CServiceManage(QObject *parent = nullptr);
protected:
    mutex m_mutex;
    QQueue<QSharedPointer<CDataStreamBase>> m_ServicePacks;
    condition_variable m_condition;
    QMap<SERVICE_THREAD_ID,CServiceLoop*>m_mapServiceLoop;
    QMap<QString,QMap<QString,QList<function<QVariant(QVariant)>>>>m_mapRecvResponseHandle;
protected:
    //void run();
    void initServiceLoop();
    void freeServiceLoop();
public:
    void registerService(IService* service,SERVICE_THREAD_ID serviceThreadId = SERVICE_THREAD_ID::ServiceThread0);
    void initModule();
    ~CServiceManage();
public slots:
    void slot_RequestService(const QSharedPointer<CDataStreamBase>& pack);
signals:
//    void signal_SendResponse(const CDataStreamWrapped pack);
    void signal_SendResponse(const QSharedPointer<CDataStreamBase> responsePack);
};

#endif // CSERVICEMANAGE_H
