#include "CMainView.h"
#include "../../Common/View/ViewCommon.h"
#include "../../Common/MyCommon.h"
#include "../../Common/CDataStructs.h"
#include "../../Common/Service/ServiceCommon.h"
#include "../../Common/Net/CNetCommon.h"
#include "../../Common/Net/CNetDataStructs.h"
#include <QDebug>
CMainView::CMainView(QWidget* parent):CWidgetView(CMAINVIEW_NAME,parent)
{
    //initModule();
}

void CMainView::initModule()
{
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(startRecord),bind(&CMainView::startRecordRecvHandle,this,std::placeholders::_1));
}

void CMainView::startRecord()
{
    QSharedPointer<CDataStream<CNetData>> data = QSharedPointer<CDataStream<CNetData>>(new CDataStream<CNetData>);
    data->serviceName = CNETSERVICE_NAME;
    data->handleFuncName = DEF_FUNC_NAME(startRecord);
    data->data.cmd = CNetMessageType_T::START_RECORD;
    requestService(data);
}

void CMainView::pauseRecord()
{
    QSharedPointer<CDataStream<CNetData>> data = QSharedPointer<CDataStream<CNetData>>(new CDataStream<CNetData>);
    data->serviceName = CNETSERVICE_NAME;
    data->handleFuncName = DEF_FUNC_NAME(pauseRecord);
    data->data.cmd = CNetMessageType_T::PAUSE_RECORD;
    requestService(data);
}

void CMainView::endRecord()
{
    QSharedPointer<CDataStream<CNetData>> data = QSharedPointer<CDataStream<CNetData>>(new CDataStream<CNetData>);
    data->serviceName = CNETSERVICE_NAME;
    data->handleFuncName = DEF_FUNC_NAME(endRecord);
    data->data.cmd = CNetMessageType_T::END_RECORD;
    requestService(data);
}

void CMainView::onStartRecord()
{
    startRecord();
}

void CMainView::onPauseRecord()
{
    pauseRecord();
}

void CMainView::onEndRecord()
{
    endRecord();
}

void CMainView::startRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    qDebug()<<"CMainView startRecordRecvHandle";
}


