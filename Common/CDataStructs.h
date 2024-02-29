#ifndef CDATASTRUCTS_H
#define CDATASTRUCTS_H
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <QDebug>
#include <QByteArray>
struct CDataStreamBase
{
public:
    QString serviceName;
    QString handleFuncName;
    template<typename T>
    T* toDataStream()
    {
        T* ptr =  dynamic_cast<T*>(this);
        return ptr;
    }
    CDataStreamBase(){}
    virtual ~CDataStreamBase(){}
};

template<typename T>
struct CDataStream:CDataStreamBase
{
    T data;
};

struct CFetalHeartData
{
    int fetalHeartOne = 0xff;
    int fetalHeartTwo = 0xff;
    int fetalHeartThree = 0xff;
};
#endif // CDATASTRUCTS_H
