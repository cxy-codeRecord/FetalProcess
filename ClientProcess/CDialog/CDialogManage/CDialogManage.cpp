#include "CDialogManage.h"
#include "../Common/Dialog/DialogCommon.h"
#include "../../Output/FetalProcess/ui_CDialogManage.h"
CDialogManage::CDialogManage(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    initModule();
}

void CDialogManage::initModule()
{
    initView();
    initHandleOnGoingStateDialog();
    initHandlePauseStateDialog();
    ui->stackedWidget->setCurrentIndex(CHandleOnGoingStateDialogIndex);
}

void CDialogManage::initView()
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void CDialogManage::initHandleOnGoingStateDialog()
{
    m_pCHandleOnGoingStateDialog = new CHandleOnGoingStateDialog(this);
    ui->stackedWidget->addWidget(m_pCHandleOnGoingStateDialog);
    connect(m_pCHandleOnGoingStateDialog,&CHandleOnGoingStateDialog::signalClose,this,&CDialogManage::close);
}

void CDialogManage::initHandlePauseStateDialog()
{
    m_pCHandlePauseStateDialog = new CHandlePauseStateDialog(this);
    ui->stackedWidget->addWidget(m_pCHandlePauseStateDialog);
    connect(m_pCHandlePauseStateDialog,&CHandlePauseStateDialog::signalClose,this,&CDialogManage::close);
}

void CDialogManage::onShowHandleOnGoingStateDialog()
{
    ui->stackedWidget->setCurrentIndex(CHandleOnGoingStateDialogIndex);
    exec();
}

void CDialogManage::onShowHandlePauseStateDialog()
{
    ui->stackedWidget->setCurrentIndex(CHandlePauseStateDialogIndex);
    exec();
}
