#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QWidget>
#include "../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class CMenuBar;
}

class CMenuBar : public CWidgetView
{
    Q_OBJECT
private:
    Ui::CMenuBar *ui;
public:
    explicit CMenuBar(QWidget *parent = nullptr);
    ~CMenuBar();
    void initModule();
protected:
    void initView();
    void initSlot();
    void initRegisterRecvResponseHandle();
protected:
    void controllerRecord(CRecordCmd cmd);
    void controllerRecordRecvHandle(QSharedPointer<CDataStreamBase>data);
protected slots:
    void onStartRecord();
signals:
    void signalShowDealOnGoingRecordDialog();
    void signalShowDealPauseRecordDialog();
protected:
    CRecordState m_recordState = CRecordState::IDLE_STATE;

};

#endif // CMENUBAR_H
