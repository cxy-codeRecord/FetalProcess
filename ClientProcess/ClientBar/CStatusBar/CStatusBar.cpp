#include "CStatusBar.h"
//#include "../Common/MyCommon.h"
#include "../Common/View/ViewCommon.h"
CStatusBar::CStatusBar(QWidget *parent):CWidgetView(CSTATUSBAR_NAME,parent)
{
   setStyleSheet("QWidget:{background-color:#000000;}");
}

void CStatusBar::initModule()
{

}
