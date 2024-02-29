#ifndef CTIMERSERVICEHANDLE_H
#define CTIMERSERVICEHANDLE_H

#include <QThread>
#include <QObject>
#include <QTimer>
#include "../Common/CDataStructs.h"
#include <QVector>
class CTimerServiceHandle : public QThread
{
    Q_OBJECT
protected:
    QVector<QSharedPointer<QTimer>> m_timerVector;
    QTimer m_timer;
public:
    explicit CTimerServiceHandle(QObject *parent = nullptr);
    ~CTimerServiceHandle();
    void initModule();
    void startTimerHandle(int ms,QSharedPointer<CDataStreamBase> base);
signals:
    void siganlRequestService(QSharedPointer<CDataStreamBase> base);
};

#endif // CTIMERSERVICEHANDLE_H
