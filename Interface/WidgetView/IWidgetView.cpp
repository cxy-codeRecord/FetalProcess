#include "IWidgetView.h"
#include "../Controller/CController.h"
#include <QDebug>
IWidgetView::IWidgetView(const QString& viewName,QWidget *parent):QWidget(parent),m_viewName(viewName)
{
}

void IWidgetView::requestService(const QSharedPointer<CDataStreamBase>& pack)
{
    emit signalRequestService(pack);
}

void IWidgetView::registerRecvResponseHandle(const QString funcName, function<void(QSharedPointer<CDataStreamBase>)>func)
{
    m_mapRecvResponseHandle[funcName] = func;
}

QString IWidgetView::getViewName()
{
    return m_viewName;
}

bool IWidgetView::getRecvResponseHandle(const QString &funcName, function<void(QSharedPointer<CDataStreamBase>)> &handleFunc)
{
    if(m_mapRecvResponseHandle.contains(funcName))
    {
       handleFunc = m_mapRecvResponseHandle[funcName];
       return true;
    }
    return false;
}

void IWidgetView::onRecvResponseHandle(const QString funcName, const QSharedPointer<CDataStreamBase> data)
{
    auto handleFunc = m_mapRecvResponseHandle[funcName];
    handleFunc(data);
}
