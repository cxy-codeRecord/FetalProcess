#include "CTimerServiceHandle.h"

CTimerServiceHandle::CTimerServiceHandle(QObject *parent) : QThread(parent)
{
    //m_timer.stop();

}

CTimerServiceHandle::~CTimerServiceHandle()
{
    quit();
    wait();
}

void CTimerServiceHandle::initModule()
{
//    m_timer.moveToThread(this);
//    moveToThread(this);
//    m_timer.start(100);
//    this->start();
//    connect(&m_timer,&QTimer::timeout,this,[]{
//        qDebug()<<"CTimerServiceHandle:"<<currentThreadId();
//    },Qt::QueuedConnection);


}

void CTimerServiceHandle::startTimerHandle(int ms, QSharedPointer<CDataStreamBase> base)
{
    QSharedPointer<QTimer> timePtr = QSharedPointer<QTimer>(new QTimer);
    m_timerVector.append(timePtr);
    connect(timePtr.get(),&QTimer::timeout,this,[=]()
    {
      emit siganlRequestService(base);
    },Qt::QueuedConnection);
    timePtr->start(ms);
}
