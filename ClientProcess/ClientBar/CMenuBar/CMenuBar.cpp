#include "CMenuBar.h"
#include "ui_CMenuBar.h"
#include "../Common/View/ViewCommon.h"
#include "../../../Common/View/ViewCommon.h"
#include "../../../Common/MyCommon.h"
#include "../../../Common/CDataStructs.h"
#include "../../../Common/Service/ServiceCommon.h"
#include "../../../Common/Net/CNetCommon.h"
#include "../../../Common/Net/CNetDataStructs.h"
#include "../../CViewHelp/CViewHelp.h"
CMenuBar::CMenuBar(QWidget* parent):CWidgetView(CMENUBAR_NAME,parent),
    ui(new Ui::CMenuBar)
{

}

void CMenuBar::initModule()
{
    ui->setupUi(this);
    initView();
    initSlot();
    initRegisterRecvResponseHandle();
}

void CMenuBar::initView()
{
    ui->controllerRecordBtn->setIcon(QIcon(":/Image/MenuBar/Start.png"));
    ui->controllerRecordBtn->setIconSize(QSize(60,60));
    ui->controllerRecordBtn->initPageButton();
    ui->controllerRecordBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->controllerRecordBtn->setText("Start\nRecording");

    ui->zeroIUPBtn->setIcon(QIcon(":/Image/MenuBar/TocoZero.png"));
    ui->zeroIUPBtn->setIconSize(QSize(60,60));
    ui->zeroIUPBtn->initPageButton();
    ui->zeroIUPBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->zeroIUPBtn->setText("Zero IUP");

    ui->nibpBtn->setIcon(QIcon(":/Image/MenuBar/NIBP.png"));
    ui->nibpBtn->setIconSize(QSize(60,60));
    ui->nibpBtn->initPageButton();
    ui->nibpBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->nibpBtn->setText("NIBP");

    ui->NoteBtn->setIcon(QIcon(":/Image/MenuBar/Note.png"));
    ui->NoteBtn->setIconSize(QSize(60,60));
    ui->NoteBtn->initPageButton();
    ui->NoteBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->NoteBtn->setText("Note");

    ui->LogBtn->setIcon(QIcon(":/Image/MenuBar/Log.png"));
    ui->LogBtn->setIconSize(QSize(60,60));
    ui->LogBtn->initPageButton();
    ui->LogBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->LogBtn->setText("Log");

    ui->SignalBtn->setIcon(QIcon(":/Image/MenuBar/Signal.png"));
    ui->SignalBtn->setIconSize(QSize(60,60));
    ui->SignalBtn->initPageButton();
    ui->SignalBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->SignalBtn->setText("Signal");

    ui->SystemMenuBtn->setIcon(QIcon(":/Image/MenuBar/Main.png"));
    ui->SystemMenuBtn->setIconSize(QSize(60,60));
    ui->SystemMenuBtn->initPageButton();
    ui->SystemMenuBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->SystemMenuBtn->setText("System");

    ui->printerBtn->setIcon(QIcon(":/Image/MenuBar/Print.png"));
    ui->printerBtn->setIconSize(QSize(60,60));
    ui->printerBtn->initPageButton();
    ui->printerBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    ui->printerBtn->setText("Print");
}

void CMenuBar::initSlot()
{
    connect(ui->controllerRecordBtn,&QPushButton::clicked,this,&CMenuBar::onStartRecord);
    connect(this,&CMenuBar::signalShowDealOnGoingRecordDialog,CViewHelp::getInstance(),&CViewHelp::signalShowDealOnGoingRecordDialog);
    connect(this,&CMenuBar::signalShowDealPauseRecordDialog,CViewHelp::getInstance(),&CViewHelp::signalShowDealPauseRecordDialog);
}

void CMenuBar::initRegisterRecvResponseHandle()
{
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_CONTROLLER_RECORD),bind(&CMenuBar::controllerRecordRecvHandle,this,std::placeholders::_1));
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
            switch (m_recordState)
            {
            case CRecordState::IDLE_STATE:
            {
                ui->controllerRecordBtn->setText("Start\nRecording");
                ui->controllerRecordBtn->setIcon(QIcon(":/Image/MenuBar/Start.png"));
                break;
            }
            case CRecordState::PAUSE_STATE:
            {
                ui->controllerRecordBtn->setText("Pause\nRecording");
                ui->controllerRecordBtn->setIcon(QIcon(":/Image/MenuBar/Stop.png"));
                break;
            }
            case CRecordState::ONGOING_STATE:
            {
                ui->controllerRecordBtn->setIcon(QIcon(":/Image/MenuBar/Start.png"));
                ui->controllerRecordBtn->setText("Run\nRecording");
                break;
            }
            }
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

CMenuBar::~CMenuBar()
{

}
