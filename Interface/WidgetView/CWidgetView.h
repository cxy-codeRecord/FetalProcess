#ifndef CWIDGETVIEW_H
#define CWIDGETVIEW_H
#include "IWidgetView.h"

class CWidgetView : public IWidgetView
{
    Q_OBJECT
public:
    explicit CWidgetView(const QString& viewName,QWidget *parent = nullptr);
protected:
    void regiserWidgetView(IWidgetView* view);
    void paintEvent(QPaintEvent *);
};

#endif // CWIDGETVIEW_H
