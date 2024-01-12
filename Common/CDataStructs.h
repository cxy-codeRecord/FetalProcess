#ifndef CDATASTRUCTS_H
#define CDATASTRUCTS_H
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <QDebug>
#include <QByteArray>
#include "MyCommon.h"


enum SERVICE_THREAD_ID
{
    ServiceThread0,
    ServiceThread1,
    ServiceThreadCount
};



#define SERVICE_THREAD_COUNT (SERVICE_THREAD_ID::ServiceThreadCount)  //根据SERVICE_THREAD_ID来计数


struct CDataStreamBase
{
    QString serviceName;
    QString viewName;
    QString handleFuncName;
    template<typename T>
    T* toData()
    {
        T* ptr =  dynamic_cast<T*>(this);
        return ptr;
    }
    CDataStreamBase(){}
    virtual ~CDataStreamBase(){}
    virtual void init(){}
};

template<typename T>
struct CDataStream:CDataStreamBase
{
    T data;
};





#endif // CDATASTRUCTS_H
