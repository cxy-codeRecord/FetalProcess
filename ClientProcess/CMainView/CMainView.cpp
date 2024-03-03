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
    //registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(startRecord),bind(&CMainView::startRecordRecvHandle,this,std::placeholders::_1));
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(controllerRecord),bind(&CMainView::controllerRecordRecvHandle,this,std::placeholders::_1));
}

void CMainView::onStartRecord()
{
    if(m_recordState == CRecordState::IDLE_STATE)
    {
        controllerRecord(CRecordCmd::START_RECORD);
    }
    else if(m_recordState == CRecordState::ONGOING_STATE)
    {

    }
    else if(m_recordState == CRecordState::PAUSE_STATE)
    {

    }
}

void CMainView::onPauseRecord()
{
    controllerRecord(CRecordCmd::PAUSE_RECORD);
}

void CMainView::onEndRecord()
{
    controllerRecord(CRecordCmd::END_RECORD);
}


void CMainView::startRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    qDebug()<<"CMainView startRecordRecvHandle";
}

void CMainView::controllerRecord(CRecordCmd cmd)
{
    QSharedPointer<CDataStream<CRecordCmd>> data = QSharedPointer<CDataStream<CRecordCmd>>(new CDataStream<CRecordCmd>);
    data->serviceName = CNETSERVICE_NAME;
    data->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    data->data = cmd;
    requestService(data);
}

void CMainView::controllerRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    if(!data.isNull())
    {
        CDataStream<CRecordState>* ptr = data->toDataStream<CDataStream<CRecordState>>();
        if(ptr)
        {
            CRecordState state = ptr->data;
            m_recordState = state;
        }
    }
}


