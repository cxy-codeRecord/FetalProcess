#ifndef CMAINVIEW_H
#define CMAINVIEW_H

#include <QObject>
#include <QWidget>
#include "../../Interface/WidgetView/CWidgetView.h"
#include <QTimer>
class CMainView : public CWidgetView
{
public:
    CMainView(QWidget* parent=nullptr);
    void initModule();
    void startRecord();
public slots:
    void onStartRecord();
protected:
    QTimer m_timer;
protected:
    void startRecordRecvHandle(QSharedPointer<CDataStreamBase>data);
};

#endif // CMAINVIEW_H
