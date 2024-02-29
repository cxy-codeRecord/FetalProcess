#ifndef CNETDATASTRUCTS_H
#define CNETDATASTRUCTS_H
#include <QByteArray>
//存放结构体和枚举


enum CNetMessageType_T
{
    ESTABLISH_CONNECT,
    START_RECORD,
    PAUSE_RECORD,
    END_RECORD,
    UPLOAD_CTG_POINTS
};

enum CNetError_T
{
    NO_ERROR,
    LOST_PACKET_ERROR
};


struct CNetData
{
    CNetMessageType_T cmd;
    QByteArray data;
};


#endif // CNETDATASTRUCTS_H
