#ifndef ISERVICE_H
#define ISERVICE_H
#include <QObject>
#include <QMap>
#include <QVariant>
#include <functional>
#include <QThread>
#include <QWidget>
#include "../Common/CDataStructs.h"
using namespace std;
class IService:public QObject
{
    Q_OBJECT
protected:
    QString m_serviceName;
    SERVICE_THREAD_ID m_serviceThreadId = SERVICE_THREAD_ID::ServiceThread0;
    QMap<QString,function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>> m_mapServiceHandleFunc;
    virtual void regiserService(const IService* service,const SERVICE_THREAD_ID& threadId)=0;
public:
    QString getServiceName();
    SERVICE_THREAD_ID getServiceThreadId();
    void setServiceThreadId(SERVICE_THREAD_ID serviceThreadId);
    IService(const QString& serviceName,const SERVICE_THREAD_ID& threadId,QObject* parent=nullptr);
    virtual void initModule() = 0;
    void registerServiceHandleFunc(const QString&& funcName,function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)> func);
    bool getServiceHandleFunc(const QString& funcName,function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>&func);
};

#endif // ISERVICE_H
