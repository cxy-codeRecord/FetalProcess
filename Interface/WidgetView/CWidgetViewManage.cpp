#include "CWidgetViewManage.h"

CWidgetViewManage::CWidgetViewManage(QObject *parent) : QObject(parent)
{

}

void CWidgetViewManage::registerWidgetView(IWidgetView* view)
{
    QString viewName = view->getViewName();
    m_mapWidgetView[viewName] = const_cast<IWidgetView*>(view);
    connect(view,&IWidgetView::signal_RequestService,this,&CWidgetViewManage::signal_RequestService);
}

void CWidgetViewManage::slot_RecvResponse(const QSharedPointer<CDataStreamBase> responsePack)
{
    const QString& viewName = responsePack->viewName;
    if(m_mapWidgetView.contains(viewName))
    {
       IWidgetView* view = m_mapWidgetView[viewName];
       function<QSharedPointer<CDataStreamBase>(QSharedPointer<CDataStreamBase>)>func;
       bool ret = view->getRecvResponseHandle(responsePack->handleFuncName,func);
       if(ret)
       {
           func(responsePack);
       }
    }
}




