#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include <QWidget>
#include "../Interface/WidgetView/CWidgetView.h"
class CStatusBar : public CWidgetView
{
    Q_OBJECT
public:
    explicit CStatusBar(QWidget *parent = nullptr);
    void initModule();
signals:

public slots:
};

#endif // CSTATUSBAR_H
