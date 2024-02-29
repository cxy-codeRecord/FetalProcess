#ifndef CDIGITALBAR_H
#define CDIGITALBAR_H
#include "../../Interface/WidgetView/CWidgetView.h"

class CDigitalBar : public CWidgetView
{
public:
    CDigitalBar(QWidget* parent=nullptr);
    void initModule();
protected:
    void startRecordRecvHandle(QSharedPointer<CDataStreamBase> data);
};

#endif // CDIGITALBAR_H
