#ifndef CSOCKBUFFER_H
#define CSOCKBUFFER_H
#include <QObject>
#include <mutex>
#include <QByteArray>
#include <QSharedPointer>
#include <QQueue>
#include "CNetMessage.h"
using namespace std;
class CSockBuffer : public QObject
{
    Q_OBJECT
public:
    explicit CSockBuffer(QObject *parent = nullptr);
public:
    QSharedPointer<CNetMessage> removeFirstNetMessage();
    QSharedPointer<CNetMessage> readFirstNetMessage();
    CNetError_T getError();
    void setError(CNetError_T error);
    void appendBufferData(const QByteArray& data);
    void appendNetMessage(QSharedPointer<CNetMessage>data);
    int getBufferSize();
    QByteArray* getBuffer();
    int getNetMessageCount();
protected:
    QQueue<QSharedPointer<CNetMessage>> m_NetMessageQueue;
    QByteArray m_buffer;
    CNetError_T m_error = CNetError_T::NO_ERROR;
//    int m_errorDataIndex = 0;


};

#endif // CSOCKBUFFER_H
