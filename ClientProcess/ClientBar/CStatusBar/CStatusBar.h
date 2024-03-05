#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include <QWidget>
#include "../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class CStatusBar;
}

class CStatusBar : public CWidgetView
{
    Q_OBJECT

public:
    explicit CStatusBar(QWidget *parent = nullptr);
    ~CStatusBar();
    void initModule();
private:
    Ui::CStatusBar *ui;
};

#endif // CSTATUSBAR_H
