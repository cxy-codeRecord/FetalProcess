#include "CMenuBar.h"
#include "../Common/View/ViewCommon.h"
#include "../../Output/FetalProcess/ui_CMenuBar.h"
#include "../../../Common/View/ViewCommon.h"
#include "../../../Common/MyCommon.h"
#include "../../../Common/CDataStructs.h"
#include "../../../Common/Service/ServiceCommon.h"
#include "../../../Common/Net/CNetCommon.h"
#include "../../../Common/Net/CNetDataStructs.h"
#include "../../CViewHelp/CViewHelp.h"
CMenuBar::CMenuBar(QWidget* parent):CWidgetView(CMENUBAR_NAME,parent),
    ui(new Ui::Form)
{

//    initView();
//    initSlot();
}

void CMenuBar::initModule()
{
    ui->setupUi(this);
    initRegisterRecvResponseHandle();
}

void CMenuBar::initView()
{
//    ui->startRecordBtn->setIcon(QIcon(":/Image/MenuBar/FetalStartRecord.svg"));
//    ui->startRecordBtn->setIconSize(QSize(60,60));
//    ui->startRecordBtn->initPageButton();
}

void CMenuBar::initSlot()
{
    //connect(ui->startRecordBtn,&QPushButton::clicked,this,&CMenuBar::onStartRecord);
    connect(this,&CMenuBar::signalShowDealOnGoingRecordDialog,CViewHelp::getInstance(),&CViewHelp::signalShowDealOnGoingRecordDialog);
    connect(this,&CMenuBar::signalShowDealPauseRecordDialog,CViewHelp::getInstance(),&CViewHelp::signalShowDealPauseRecordDialog);
}

void CMenuBar::initRegisterRecvResponseHandle()
{
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(controllerRecord),bind(&CMenuBar::controllerRecordRecvHandle,this,std::placeholders::_1));
}

void CMenuBar::controllerRecord(CRecordCmd cmd)
{
    QSharedPointer<CDataStream<CRecordCmd>> data = QSharedPointer<CDataStream<CRecordCmd>>(new CDataStream<CRecordCmd>);
    data->serviceName = CNETSERVICE_NAME;
    data->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    data->data = cmd;
    requestService(data);
}

void CMenuBar::controllerRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
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

void CMenuBar::onStartRecord()
{
    if(m_recordState == CRecordState::IDLE_STATE)
    {
        controllerRecord(CRecordCmd::START_RECORD);
    }
    else if(m_recordState == CRecordState::ONGOING_STATE)
    {
        emit signalShowDealOnGoingRecordDialog();
    }
    else if(m_recordState == CRecordState::PAUSE_STATE)
    {
        emit signalShowDealPauseRecordDialog();
    }
}
