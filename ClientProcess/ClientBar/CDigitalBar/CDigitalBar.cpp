#include "CDigitalBar.h"
//#include "../../Common/MyCommon.h"
#include "../../Common/View/ViewCommon.h"
CDigitalBar::CDigitalBar(QWidget* parent):CWidgetView (CDIGITALBAR_NAME,parent)
{
    setStyleSheet("QWidget:{background-color:#1E1E1E;}");
}

void CDigitalBar::initModule()
{
    registerRecvResponseHandle("startRecordRecvHandle",bind(&CDigitalBar::startRecordRecvHandle,this,std::placeholders::_1));
}

void CDigitalBar::startRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    qDebug()<<"CDigitalBar startRecordRecvHandle";
}
