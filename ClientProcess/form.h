#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include "../Common/MyCommon.h"
#include <QProcess>
#include "CDialog/CDialogManage/CDialogManage.h"
namespace Ui {
class Form;
}

class Form : public QMainWindow
{
    Q_OBJECT
    SINGLETON(Form)
protected:
    QProcess m_process;
//    /CDialogManage m_DialogManage;
protected:
    void initView();
    void initSlot();
public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void initModule();
private:
    Ui::Form *ui;
protected slots:
    void onReadStandardOutput();
};

#endif // FORM_H
