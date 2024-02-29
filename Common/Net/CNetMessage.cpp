#include "CNetMessage.h"

CNetMessage::CNetMessage(QObject *parent) : QObject(parent)
{

}

void CNetMessage::setData(const QByteArray& data)
{
    m_data = data;
}

QByteArray CNetMessage::getData()
{
    return m_data;
}


void CNetMessage::appendData(char *src, int len)
{
    m_data.append(src,len);
}

void CNetMessage::setDataLength(const int& length)
{
    m_dataLength = length;
}

int CNetMessage::getDataLength()
{
    return m_dataLength;
}

void CNetMessage::setDataType(const int& type)
{
    m_dataType = type;
}

int CNetMessage::getDataType()
{
    return m_dataType;
}

void CNetMessage::setDataIndex(int index)
{
    m_dataIndex = index;
}

int CNetMessage::getDataIndex()
{
    return m_dataIndex;
}
