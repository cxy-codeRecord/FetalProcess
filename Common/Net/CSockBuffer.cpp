#include "CSockBuffer.h"
#include <QDebug>
CSockBuffer::CSockBuffer(QObject *parent) : QObject(parent)
{

}

void CSockBuffer::appendNetMessage(QSharedPointer<CNetMessage> data)
{
    m_NetMessageQueue.append(data);
}


QSharedPointer<CNetMessage> CSockBuffer::removeFirstNetMessage()
{
    QSharedPointer<CNetMessage>data;
    if(m_NetMessageQueue.empty())
    {
        return data;
    }
    data = m_NetMessageQueue.head();
    m_NetMessageQueue.pop_front();
    return data;

}

QSharedPointer<CNetMessage> CSockBuffer::readFirstNetMessage()
{
    QSharedPointer<CNetMessage>data;
    if(m_NetMessageQueue.empty())
    {
        return data;
    }
    data = m_NetMessageQueue.head();
    return data;
}


CNetError_T CSockBuffer::getError()
{
    return m_error;
}

void CSockBuffer::setError(CNetError_T error)
{
    if(error!=m_error)
    {
        qDebug()<<"error:"<<error;
        m_error = error;
    }
}

void CSockBuffer::appendBufferData(const QByteArray &data)
{
    m_buffer.append(data);
}

int CSockBuffer::getBufferSize()
{
    return m_buffer.size();
}

QByteArray* CSockBuffer::getBuffer()
{
    return &m_buffer;
}

int CSockBuffer::getNetMessageCount()
{
    return m_NetMessageQueue.length();
}

//void CSockBuffer::setErrorDataIndex(int index)
//{
//    m_errorDataIndex = index;
//}

//int CSockBuffer::getErrorDataIndex()
//{
//    return m_errorDataIndex;
//}




