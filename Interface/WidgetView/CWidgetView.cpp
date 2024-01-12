#include "CWidgetView.h"
#include "../Controller/CController.h"
#include <QStyleOption>
#include <QPainter>
CWidgetView::CWidgetView(const QString& viewName,QWidget *parent)
    :IWidgetView (viewName,parent)
{
    regiserWidgetView(this);
}


void CWidgetView::regiserWidgetView(IWidgetView *view)
{
    CController::getInstance()->registerView(this);
}

//需要自定义paintEvent，否则QWidget使用样式表会失效
void CWidgetView::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
