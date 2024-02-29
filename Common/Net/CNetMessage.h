#ifndef CNETMESSAGE_H
#define CNETMESSAGE_H

#include <QObject>
#include <QByteArray>
#include <QSharedPointer>
#include <mutex>
#include "CNetDataStructs.h"
using namespace std;
class CNetMessage : public QObject
{
    Q_OBJECT
public:
    explicit CNetMessage(QObject *parent = nullptr);
protected:
    int m_dataType = 0;
    int m_dataLength = 0;
    int m_dataIndex = 0;
    QByteArray m_data;
public:
    void setData(const QByteArray& data);
    QByteArray getData();
    void appendData(char* src,int len);
    void setDataLength(const int& length);
    int getDataLength();
    void setDataType(const int& type);
    int getDataType();
    void setDataIndex(int index);
    int getDataIndex();
};

#endif // CNETMESSAGE_H
