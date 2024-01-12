#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QObject>
#include <QWidget>
#include "../../Interface/WidgetView/CWidgetView.h"
class CMainView : public CWidgetView
{
public:
    CMainView(QWidget* parent=nullptr);
    void initModule();
};

#endif // CMAINVIEW_H
