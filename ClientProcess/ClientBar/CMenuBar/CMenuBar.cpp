#include "CMenuBar.h"
#include "../../Common/View/ViewCommon.h"
CMenuBar::CMenuBar(QWidget* parent):CWidgetView(CMENUBAR_NAME,parent)
{
    setStyleSheet("QWidget:{background-color:#000000;}");
}

void CMenuBar::initModule()
{

}
