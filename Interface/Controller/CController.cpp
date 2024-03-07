#include "CController.h"

CController::CController(QObject *parent):IController(parent),
    m_pServiceManage(CServiceManage::getInstance()),
    m_pWidgetViewManage(CWidgetViewManage::getInstance())
{

}

void CController::initModule()
{
    initWidgetViewManage();
    initServiceManage();
    initSlot();
}

void CController::initServiceManage()
{
    //m_pServiceManage->initServiceLoop();
    m_pServiceManage->createServiceLoop();
    CServiceGenerator::getInstance()->initModule();
    m_pServiceManage->startServiceLoop();
}

void CController::initWidgetViewManage()
{
    Form::getInstance()->initModule();
    m_pWidgetViewManage->initModule();
    Form::getInstance()->show();
}

void CController::initServiceGenerator()
{
    m_pServiceManage->initServiceModule();
}


void CController::registerService(IService *service,SERVICE_THREAD_ID serviceThreadId)
{
    m_pServiceManage->registerService(service,serviceThreadId);
}

void CController::registerView(IWidgetView *widgetView)
{
    m_pWidgetViewManage->registerWidgetView(widgetView);
}

void CController::startTimerHandle(int ms, QSharedPointer<CDataStreamBase> base)
{
    m_pServiceManage->startTimerHanle(ms,base);
}

void CController::initSlot()
{
    connect(m_pWidgetViewManage,&CWidgetViewManage::signalRequestService,m_pServiceManage,&CServiceManage::onRequestService,Qt::QueuedConnection);
    connect(m_pServiceManage,&CServiceManage::signalSendResponse,m_pWidgetViewManage,&CWidgetViewManage::onRecvResponse,Qt::QueuedConnection);
}


