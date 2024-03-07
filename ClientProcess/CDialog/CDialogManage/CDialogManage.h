#ifndef CDIALOGMANAGE_H
#define CDIALOGMANAGE_H

#include <QDialog>
#include <QObject>
#include "../CHandleOnGoingStateDialog/CHandleOnGoingStateDialog.h"
#include "../CHandlePauseStateDialog/CHandlePauseStateDialog.h"
namespace Ui {
class Dialog;
}
class CDialogManage : public QDialog
{
public:
    CDialogManage(QWidget *parent = nullptr);
    CHandleOnGoingStateDialog* m_pCHandleOnGoingStateDialog = nullptr;
    CHandlePauseStateDialog* m_pCHandlePauseStateDialog = nullptr;
protected:
    void initModule();
    void initView();
    void initHandleOnGoingStateDialog();
    void initHandlePauseStateDialog();
public slots:
    void onShowHandleOnGoingStateDialog();
    void onShowHandlePauseStateDialog();
private:
    Ui::Dialog *ui;
};

#endif // CDIALOGMANAGE_H
