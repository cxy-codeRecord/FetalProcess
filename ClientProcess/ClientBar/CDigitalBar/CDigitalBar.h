#ifndef CDIGITALBAR_H
#define CDIGITALBAR_H
#include "../../Interface/WidgetView/CWidgetView.h"

class CDigitalBar : public CWidgetView
{
public:
    CDigitalBar(QWidget* parent=nullptr);
    void initModule();
};

#endif // CDIGITALBAR_H
