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
public slots:
    void onStartRecord();
    void onPauseRecord();
    void onEndRecord();
protected:
    QTimer m_timer;
    CRecordState m_recordState = CRecordState::IDLE_STATE;
protected:
    void startRecordRecvHandle(QSharedPointer<CDataStreamBase>data);
    void controllerRecord(CRecordCmd cmd);
    void controllerRecordRecvHandle(QSharedPointer<CDataStreamBase>data);
//signals:
//    void signalHandleRecordState(CRecordState state);
    void signalShowDealOnGoingRecordDialog();
    void signalShowDealPauseRecordDialog();
};

#endif // CMAINVIEW_H
