#include "form.h"
#include "../../Output/FetalProcess/ui_form.h"
#include "../Common/MyCommon.h"
Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form)
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

void Form::onReadStandardOutput()
{

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
    ui->startRecordBtn->setIcon(QIcon(":/Image/MenuBar/FetalStartRecord.svg"));
    ui->startRecordBtn->setIconSize(QSize(60,60));
    ui->startRecordBtn->initPageButton();
}

void Form::initSlot()
{
    connect(ui->startRecordBtn,&QPushButton::clicked,ui->mainView,&CMainView::onStartRecord);
    connect(ui->digitalBar,&CDigitalBar::signalFetalHeartOneData,ui->mainView,[=](int data){
        ui->fetalDataOneLabel->setText(QString().setNum(data));
    });
    connect(ui->digitalBar,&CDigitalBar::signalFetalHeartTwoData,ui->mainView,[=](int data){
        ui->fetalDataTwoLabel->setText(QString().setNum(data));
    });
    connect(ui->digitalBar,&CDigitalBar::signalFetalHeartThreeData,ui->mainView,[=](int data){
        ui->fetalDataThreeLabel->setText(QString().setNum(data));
    });
}
