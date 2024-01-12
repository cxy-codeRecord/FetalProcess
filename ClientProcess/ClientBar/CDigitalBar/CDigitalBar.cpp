#include "CDigitalBar.h"
#include "../../Common/MyCommon.h"
CDigitalBar::CDigitalBar(QWidget* parent):CWidgetView (CDIGITALBAR_NAME,parent)
{
    setStyleSheet("QWidget:{background-color:#1E1E1E;}");
}

void CDigitalBar::initModule()
{

}
