#ifndef CDIGITALBAR_H
#define CDIGITALBAR_H

#include <QWidget>
#include "../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class CDigitalBar;
}

class CDigitalBar : public CWidgetView
{
    Q_OBJECT

public:
    explicit CDigitalBar(QWidget *parent = nullptr);
    ~CDigitalBar();
    void initModule();
private:
    Ui::CDigitalBar *ui;
protected:
    void getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase>data);
    void controllerRecordRecvHandle(QSharedPointer<CDataStreamBase>data);
signals:
    void signalFetalHeartOneData(int data);
    void signalFetalHeartTwoData(int data);
    void signalFetalHeartThreeData(int data);
};

#endif // CDIGITALBAR_H
