#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QObject>
#include "../Interface/WidgetView/CWidgetView.h"
namespace Ui {
class Form;
}

class CMenuBar : public CWidgetView
{
    Q_OBJECT
private:
    Ui::Form *ui;
protected:
    CRecordState m_recordState = CRecordState::IDLE_STATE;
public:
    CMenuBar(QWidget* parent = nullptr);
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
};

#endif // CMENUBAR_H
