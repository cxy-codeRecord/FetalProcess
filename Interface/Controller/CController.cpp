#include "CController.h"

CController::CController(QObject *parent):IController(parent),
    m_pServiceManage(CServiceManage::getInstance()),
    m_pWidgetViewManage(CWidgetViewManage::getInstance())
{

}

void CController::initModule()
{
    m_pServiceManage->initModule();
    m_pWidgetViewManage->initModule();
    initSlot();
}


void CController::registerService(IService *service,SERVICE_THREAD_ID serviceThreadId)
{
    m_pServiceManage->registerService(service,serviceThreadId);
}

void CController::registerView(IWidgetView *widgetView)
{
    m_pWidgetViewManage->registerWidgetView(widgetView);
}

void CController::initSlot()
{
    connect(m_pWidgetViewManage,&CWidgetViewManage::signal_RequestService,m_pServiceManage,&CServiceManage::slot_RequestService);
    connect(m_pServiceManage,&CServiceManage::signal_SendResponse,m_pWidgetViewManage,&CWidgetViewManage::slot_RecvResponse);
}


