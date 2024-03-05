#ifndef CDIALOGMANAGE_H
#define CDIALOGMANAGE_H

#include <QDialog>
#include <QObject>
#include "../CHandleOnGoingStateDialog/CHandleOnGoingStateDialog.h"
namespace Ui {
class Dialog;
}
class CDialogManage : public QDialog
{
public:
    CDialogManage(QWidget *parent = nullptr);
    CHandleOnGoingStateDialog* m_pCHandleOnGoingStateDialog = nullptr;
protected:
    void initModule();
private:
    Ui::Dialog *ui;
};

#endif // CDIALOGMANAGE_H
