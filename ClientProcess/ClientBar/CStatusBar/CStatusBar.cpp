#include "CStatusBar.h"
#include "ui_CStatusBar.h"
#include "../Common/View/ViewCommon.h"
CStatusBar::CStatusBar(QWidget *parent) :
    CWidgetView(CSTATUSBAR_NAME,parent),
    ui(new Ui::CStatusBar)
{
    ui->setupUi(this);
}

CStatusBar::~CStatusBar()
{
    delete ui;
}

void CStatusBar::initModule()
{

}
