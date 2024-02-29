#include "CSockDataHandle.h"
#include <stdlib.h>
#include "CNetCommon.h"
CSockDataHandle::CSockDataHandle(QTcpSocket *tcpSocket, QObject *parent) : QObject(parent)
{
    m_pTcpSocket = tcpSocket;
}

CSockDataHandle::~CSockDataHandle()
{

}

void CSockDataHandle::parseReadSockBufferData()
{
    //数据包 DD(1B) BB(1B) AA(1B) 索引号(4B) 类型(2B) 数据长度(4B) 数据(N*B) EE(1B) BB(1B) AA(1B)
    bool ret = (m_ReadSockBuffer.getBufferSize()>=(int)NET_MIN_PACKET_LENGTH);
    if(!ret)return;
    while(ret)
    {
        QByteArray* buffer = m_ReadSockBuffer.getBuffer();
        char& Begin1 = buffer->data()[0];
        char& Begin2 = buffer->data()[1];
        char& Begin3 = buffer->data()[2];
        if((Begin1 == (char)0xDD)
                &&(Begin2 == (char)0xBB)
                &&(Begin3 == (char)0xAA))
        {
            int dataLen = 0;
            int dataType = 0;
            int dataIndex = 0;
            int packetHeadBeginPos = 0;
            int packetHeadEndPos = 2;
            int packetIndexBeginPos = packetHeadEndPos+1;
            int packetIndexEndPos = packetIndexBeginPos+3;
            int packetTypeBeginPos = packetIndexEndPos + 1;
            int packetTypeEndPos = packetTypeBeginPos + 1;
            int packetDataLengthBeginPos = packetTypeEndPos + 1;
            int packetDataLengthEndPos = packetDataLengthBeginPos + 3;
            memcpy(&dataIndex,&buffer->data()[packetIndexBeginPos],4);
            memcpy(&dataLen,&buffer->data()[packetDataLengthBeginPos],4);
            memcpy(&dataType,&buffer->data()[packetTypeBeginPos],2);
            int buffSize = m_ReadSockBuffer.getBufferSize();
            if(m_ReadSockBuffer.getBufferSize()>=packetDataLengthEndPos + 3)
            {
                int packetDataBeginPos = packetDataLengthEndPos + 1;
                int packetDataEndPos = packetDataBeginPos + dataLen - 1;
                int packetTailBeginPos = packetDataEndPos + 1;
                int packetTailEndPos = packetTailBeginPos + 2;
                char& end1 = buffer->data()[packetTailBeginPos];
                char& end2 = buffer->data()[packetTailBeginPos+1];
                char& end3 = buffer->data()[packetTailBeginPos+2];
                if((end1==(char)0xEE)
                        &&(end2==(char)0xBB)
                        &&(end3==(char)0xAA))
                {
                    QSharedPointer<CNetMessage> packetMessage = QSharedPointer<CNetMessage>(new CNetMessage);
                    packetMessage->setDataIndex(dataIndex);
                    packetMessage->setDataLength(dataLen);
                    packetMessage->setDataType(dataType);
                    packetMessage->appendData(&buffer->data()[packetDataBeginPos],dataLen);
                    m_ReadSockBuffer.appendNetMessage(packetMessage);
                    buffer->remove(packetHeadBeginPos,packetTailEndPos+1);
                    m_ReadSockBuffer.setError(CNetError_T::NO_ERROR);
                }
                else
                {
                    m_ReadSockBuffer.setError(CNetError_T::LOST_PACKET_ERROR);
                    //buffer->remove(packetHeadBeginPos,packetTailEndPos+1);
                    buffer->remove(0,3);
                }
            }
        }
        else
        {
            m_ReadSockBuffer.setError(CNetError_T::LOST_PACKET_ERROR);
            buffer->remove(0,1);
        }
        ret = (m_ReadSockBuffer.getBufferSize()>=(int)NET_MIN_PACKET_LENGTH);
    }
}

void CSockDataHandle::appendReadBufferData(const QByteArray &data)
{
    m_ReadSockBuffer.appendBufferData(data);
}

QSharedPointer<CNetMessage> CSockDataHandle::readFirstNetMessage()
{
    return m_ReadSockBuffer.readFirstNetMessage();
}

QSharedPointer<CNetMessage> CSockDataHandle::removeFirstNetMessage()
{
    return m_ReadSockBuffer.removeFirstNetMessage();
}

int CSockDataHandle::getNetMessageCount()
{
    return m_ReadSockBuffer.getNetMessageCount();
}

void CSockDataHandle::sendNetData(int cmd, QByteArray& data)
{
    if(m_pTcpSocket)
    {
        QByteArray wrappedData;
        static int index = 0;
        int dataLen = data.length();
        wrappedData.append((char)NET_HEAD_COMMAND1);
        wrappedData.append((char)NET_HEAD_COMMAND2);
        wrappedData.append((char)NET_HEAD_COMMAND3);
        wrappedData.append((char*)&index,4);
        wrappedData.append((char*)&cmd,2);
        wrappedData.append((char*)&dataLen,4);
        wrappedData.append(data);
        wrappedData.append((char)NET_TAIL_COMMAND1);
        wrappedData.append((char)NET_TAIL_COMMAND2);
        wrappedData.append((char)NET_TAIL_COMMAND3);
        index++;
        m_pTcpSocket->write(wrappedData,wrappedData.length());
        m_pTcpSocket->waitForBytesWritten();
        m_pTcpSocket->flush();
    }
}

void CSockDataHandle::recvNetData()
{
    if(m_pTcpSocket)
    {
        QByteArray readData = m_pTcpSocket->readAll();
        if(readData.isNull())return;
        this->appendReadBufferData(readData);
        this->parseReadSockBufferData();
        int count = this->getNetMessageCount();
        for(int i=0;i<count;i++)
        {
            QSharedPointer<CNetMessage> netMessage = this->readFirstNetMessage();
            if(!netMessage.isNull())
            {
                handleNetMessage(netMessage);
                this->removeFirstNetMessage();
            }
        }
    }
}

QTcpSocket *CSockDataHandle::getTcpSocket()
{
    return m_pTcpSocket;
}
