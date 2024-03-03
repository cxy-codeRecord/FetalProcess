#ifndef CDIGITALBAR_H
#define CDIGITALBAR_H
#include "../../Interface/WidgetView/CWidgetView.h"

class CDigitalBar : public CWidgetView
{
    Q_OBJECT
public:
    CDigitalBar(QWidget* parent=nullptr);
    void initModule();
protected:
    void startRecordRecvHandle(QSharedPointer<CDataStreamBase> data);
    void getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase>data);
signals:
    void signalFetalHeartOneData(int data);
    void signalFetalHeartTwoData(int data);
    void signalFetalHeartThreeData(int data);
};

#endif // CDIGITALBAR_H
