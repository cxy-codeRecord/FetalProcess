#ifndef CHANDLEPAUSESTATEDIALOG_H
#define CHANDLEPAUSESTATEDIALOG_H

#include <QWidget>
#include "../../../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class CHandlePauseStateDialog;
}

class CHandlePauseStateDialog : public CWidgetView
{
    Q_OBJECT

public:
    explicit CHandlePauseStateDialog(QWidget *parent = nullptr);
    ~CHandlePauseStateDialog();
protected:
    void initModule();
signals:
    void signalClose();
protected slots:
    void onContinueRecord();
    void onEndRecord();
    void onCancel();
private:
    Ui::CHandlePauseStateDialog *ui;
};

#endif // CHANDLEPAUSESTATEDIALOG_H
