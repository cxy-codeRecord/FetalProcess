#ifndef CSERVICELOOP_H
#define CSERVICELOOP_H

#include <QObject>
#include <QThread>
#include <atomic>
#include <condition_variable>
#include <QQueue>
#include "IService.h"
#include "../Common/CDataStructs.h"
using namespace std;
class CServiceLoop : public QThread
{
    Q_OBJECT
protected:
    atomic<bool> m_Running;
    condition_variable m_condition;
    QQueue<QSharedPointer<CDataStreamBase>> m_ServicePacks;
    std::mutex m_mutex;
    QMap<QString,IService*> m_mapService;
public:
    CServiceLoop(QObject* parent = nullptr);
    ~CServiceLoop();
    void initModule();
    void startRunning();
    void stopRunning();
    void run();
    void addService(const QString& serviceName,IService* service);
    bool containService(const QString& serviceName);
    void requestService(const QSharedPointer<CDataStreamBase> pack);
signals:
    //void signal_SendResponse(const CDataStreamWrapped pack);
    void signal_SendResponse(const QSharedPointer<CDataStreamBase> responsePack);
};

#endif // CSERVICELOOP_H
