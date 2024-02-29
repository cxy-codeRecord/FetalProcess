#include "CWidgetViewManage.h"

CWidgetViewManage::CWidgetViewManage(QObject *parent) : QObject(parent)
{

}

void CWidgetViewManage::registerWidgetView(IWidgetView* view)
{
    QString viewName = view->getViewName();
    m_vectorWidgetView.push_back(view);
    connect(view,&IWidgetView::signalRequestService,this,&CWidgetViewManage::signalRequestService);
}

void CWidgetViewManage::onRecvResponse(const QString funcName, const QSharedPointer<CDataStreamBase> responsePack)
{
    auto it = m_vectorWidgetView.begin();
    while(it!= m_vectorWidgetView.end())
    {
        function<void(QSharedPointer<CDataStreamBase>)>func;
        bool ret = (*it)->getRecvResponseHandle(funcName,func);
        if(ret)
        {
            func(responsePack);
        }
        it++;
    }
}




