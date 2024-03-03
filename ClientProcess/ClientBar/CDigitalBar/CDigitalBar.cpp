#include "CDigitalBar.h"
//#include "../../Common/MyCommon.h"
#include "../Common/View/ViewCommon.h"
CDigitalBar::CDigitalBar(QWidget* parent):CWidgetView (CDIGITALBAR_NAME,parent)
{
    setStyleSheet("QWidget:{background-color:#1E1E1E;}");
}

void CDigitalBar::initModule()
{
    registerRecvResponseHandle("startRecordRecvHandle",bind(&CDigitalBar::startRecordRecvHandle,this,std::placeholders::_1));
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_GET_FETAL_HEART_DATA),bind(&CDigitalBar::getFetalHeartDataRecvHandle,this,std::placeholders::_1));
}

void CDigitalBar::startRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    qDebug()<<"CDigitalBar startRecordRecvHandle";
}

void CDigitalBar::getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    CDataStream<CFetalHeartData>* ptr = data->toDataStream<CDataStream<CFetalHeartData>>();
    static int dataIndex = 0;
    if(ptr)
    {
        int heartOne = ptr->data.fetalHeartOne + FHR_YAXIS_OFFSET;
        int heartTwo = ptr->data.fetalHeartTwo + FHR_YAXIS_OFFSET;
        int heartThree = ptr->data.fetalHeartThree + FHR_YAXIS_OFFSET;
        emit signalFetalHeartOneData(heartOne);
        emit signalFetalHeartTwoData(heartTwo);
        emit signalFetalHeartThreeData(heartThree);
    }
}
