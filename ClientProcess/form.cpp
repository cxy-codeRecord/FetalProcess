#include "form.h"
#include "../../Output/FetalProcess/ui_form.h"
#include "../Common/MyCommon.h"
#include "CViewHelp/CViewHelp.h"
Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form),
    m_DialogManage(this)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::initModule()
{
    initView();
    initSlot();
}

void Form::initView()
{
    setWindowFlags(Qt::FramelessWindowHint);
    QRect winRect = QApplication::desktop()->screenGeometry();
    int winWidth = winRect.width();
    int winHeight = winRect.height();
    int posX = (winWidth - this->width())/2;
    int posY = (winHeight - this->height())/2;
    move(posX,posY);
}

void Form::initSlot()
{
    connect(CViewHelp::getInstance(),&CViewHelp::signalShowDealOnGoingRecordDialog,&m_DialogManage,&CDialogManage::onShowHandleOnGoingStateDialog);
    connect(CViewHelp::getInstance(),&CViewHelp::signalShowDealPauseRecordDialog,&m_DialogManage,&CDialogManage::onShowHandlePauseStateDialog);
}
