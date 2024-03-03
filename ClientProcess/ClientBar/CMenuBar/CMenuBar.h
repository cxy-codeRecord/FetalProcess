#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QObject>
#include "../Interface/WidgetView/CWidgetView.h"
class CMenuBar : public CWidgetView
{
public:
    CMenuBar(QWidget* parent = nullptr);
    void initModule();
};

#endif // CMENUBAR_H
