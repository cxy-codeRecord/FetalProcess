#include "CDialogManage.h"
#include "../../Output/FetalProcess/ui_CDialogManage.h"
CDialogManage::CDialogManage(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    initModule();
}

void CDialogManage::initModule()
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    m_pCHandleOnGoingStateDialog = new CHandleOnGoingStateDialog(this);
    ui->stackedWidget->addWidget(m_pCHandleOnGoingStateDialog);
    ui->stackedWidget->setCurrentIndex(0);
    connect(m_pCHandleOnGoingStateDialog,&CHandleOnGoingStateDialog::signalClose,this,&CDialogManage::close);
}
