#ifndef CDATASTRUCTS_H
#define CDATASTRUCTS_H
#include <QString>
#include <QVariant>
#include <QMetaType>
#include <QDebug>
#include <QByteArray>
#include <QSharedPointer>
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
    static QSharedPointer<CDataStream<T>> createDataStream();
};

template <typename T>
QSharedPointer<CDataStream<T>> CDataStream<T>::createDataStream()
{
    QSharedPointer<CDataStream<T>> ptr = QSharedPointer<CDataStream<T>>(new CDataStream<T>);
    return ptr;
}

struct CFetalHeartData
{
    int fetalHeartOne = 0xff;
    int fetalHeartTwo = 0xff;
    int fetalHeartThree = 0xff;
};

enum class CRecordState
{
    INIT_STATE,
    IDLE_STATE,
    PAUSE_STATE,
    ONGOING_STATE,
    ERROR_STATE
};

enum class CRecordCmd
{
    START_RECORD,
    PAUSE_RECORD,
    END_RECORD
};

#endif // CDATASTRUCTS_H
