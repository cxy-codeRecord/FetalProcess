#ifndef SERVICECOMMON_H
#define SERVICECOMMON_H

#define SERVICE_THREAD_COUNT (SERVICE_THREAD_ID::ServiceThreadCount)  //根据SERVICE_THREAD_ID来计数
enum SERVICE_THREAD_ID
{
    ServiceThread0,
    ServiceThread1,
    ServiceThread2,
    ServiceThread3,
    ServiceThreadCount
};
#define CNETSERVICE_NAME "CNetService"



#define SERVICE_FUNC_SEND_NET_DATA "sendNetData"
#define SERVICE_FUNC_START_RECORD  "startRecord"
#define SERVICE_FUNC_RECV_NETDATA  "recvNetData"
#define SERVICE_FUNC_GET_FETAL_HEART_DATA "getFetalHeartData"
#define SERVICE_FUNC_CONTROLLER_RECORD "controllerRecord"




#endif
