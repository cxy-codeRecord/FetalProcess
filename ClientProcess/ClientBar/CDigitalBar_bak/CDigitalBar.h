#ifndef CDIGITALBAR_H
#define CDIGITALBAR_H
#include "../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class Form;
}
class CDigitalBar : public CWidgetView
{
    Q_OBJECT
private:
    Ui::Form *ui;
public:
    CDigitalBar(QWidget* parent=nullptr);
    void initModule();
protected:
    void getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase>data);
signals:
    void signalFetalHeartOneData(int data);
    void signalFetalHeartTwoData(int data);
    void signalFetalHeartThreeData(int data);
};

#endif // CDIGITALBAR_H
