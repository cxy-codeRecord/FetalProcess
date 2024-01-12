#include "form.h"
#include "ui_form.h"
#include "../Common/MyCommon.h"
Form::Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->startRecordBtn->setIcon(QIcon(":/Image/MenuBar/FetalStartRecord.svg"));
    ui->startRecordBtn->setIconSize(QSize(60,60));
    ui->startRecordBtn->initPageButton();

}

Form::~Form()
{
    delete ui;
}

void Form::initModule()
{
    resize(CMAINWIN_WIDTH,CMAINWIN_HEIGHT);
    setWindowFlags(Qt::FramelessWindowHint);
}
