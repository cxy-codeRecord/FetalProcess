#include "CHandlePauseStateDialog.h"
#include "ui_CHandlePauseStateDialog.h"
#include "../Common/View/ViewCommon.h"
#include "../Common/CDataStructs.h"
#include "../Common/Service/ServiceCommon.h"
CHandlePauseStateDialog::CHandlePauseStateDialog(QWidget *parent) :
    CWidgetView(CHANDLE_PAUSESTATE_VIWE_NAME,parent),
    ui(new Ui::CHandlePauseStateDialog)
{
    ui->setupUi(this);
}

CHandlePauseStateDialog::~CHandlePauseStateDialog()
{
    delete ui;
}

void CHandlePauseStateDialog::initModule()
{
    ui->frame->move((this->width()-ui->frame->width())/2,(this->height()-ui->frame->height())/2);
    connect(ui->continueRecordBtn,&QPushButton::clicked,this,&CHandlePauseStateDialog::onContinueRecord);
    connect(ui->endRecordBtn,&QPushButton::clicked,this,&CHandlePauseStateDialog::onEndRecord);
    connect(ui->cancelBtn,&QPushButton::clicked,this,&CHandlePauseStateDialog::onCancel);
}

void CHandlePauseStateDialog::onContinueRecord()
{
    QSharedPointer<CDataStream<CRecordCmd>> ptr = CDataStream<CRecordCmd>::createDataStream();
    ptr->data = CRecordCmd::START_RECORD;
    ptr->serviceName = CNETSERVICE_NAME;
    ptr->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    requestService(ptr);
    emit signalClose();
}

void CHandlePauseStateDialog::onEndRecord()
{
    QSharedPointer<CDataStream<CRecordCmd>> ptr = CDataStream<CRecordCmd>::createDataStream();
    ptr->data = CRecordCmd::END_RECORD;
    ptr->serviceName = CNETSERVICE_NAME;
    ptr->handleFuncName = SERVICE_FUNC_CONTROLLER_RECORD;
    requestService(ptr);
    emit signalClose();
}

void CHandlePauseStateDialog::onCancel()
{
    emit signalClose();
}
