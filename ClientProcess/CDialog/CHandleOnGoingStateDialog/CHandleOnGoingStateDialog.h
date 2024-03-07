#ifndef CHANDLEONGOINGSTATEDIALOG_H
#define CHANDLEONGOINGSTATEDIALOG_H

#include <QWidget>
#include "../../../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class CHandleOnGoingStateDialog;
}

class CHandleOnGoingStateDialog : public CWidgetView
{
    Q_OBJECT

public:
    explicit CHandleOnGoingStateDialog(QWidget *parent = nullptr);
    ~CHandleOnGoingStateDialog();
    void initModule();
signals:
    void signalClose();
protected slots:
    void onPauseRecord();
    void onEndRecord();
    void onCancel();
private:
    Ui::CHandleOnGoingStateDialog *ui;
};

#endif // CHANDLEONGOINGSTATEDIALOG_H
