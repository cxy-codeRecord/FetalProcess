#include "CHandleOnGoingStateDialog.h"
#include "ui_CHandleOnGoingStateDialog.h"
#include "../Common/View/ViewCommon.h"
#include "../Common/CDataStructs.h"
#include "../Common/Service/ServiceCommon.h"
CHandleOnGoingStateDialog::CHandleOnGoingStateDialog(QWidget *parent) :
    CWidgetView(CHANDONGOINGSTATEVIWE_NAME,parent),
    ui(new Ui::CHandleOnGoingStateDialog)
{
    ui->setupUi(this);
    initModule();
}

CHandleOnGoingStateDialog::~CHandleOnGoingStateDialog()
{
    delete ui;
}

void CHandleOnGoingStateDialog::initModule()
{
    ui->frame->move((this->width()-ui->frame->width())/2,(this->height()-ui->frame->height())/2);
    connect(ui->pauseRecordBtn,&QPushButton::clicked,this,&CHandleOnGoingStateDialog::onPauseRecord);
    connect(ui->endRecordBtn,&QPushButton::clicked,this,&CHandleOnGoingStateDialog::onEndRecord);
}

void CHandleOnGoingStateDialog::onPauseRecord()
{
    QSharedPointer<CDataStream<CRecordCmd>> ptr = CDataStream<CRecordCmd>::createDataStream();
    ptr->data = CRecordCmd::PAUSE_RECORD;
    ptr->serviceName = CNETSERVICE_NAME;
    ptr->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    requestService(ptr);
    emit signalClose();
}

void CHandleOnGoingStateDialog::onEndRecord()
{
    QSharedPointer<CDataStream<CRecordCmd>> ptr = CDataStream<CRecordCmd>::createDataStream();
    ptr->data = CRecordCmd::END_RECORD;
    ptr->serviceName = CNETSERVICE_NAME;
    ptr->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    requestService(ptr);
    emit signalClose();
}

