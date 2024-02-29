#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QObject>
#include "IController.h"
#include "../Service/CServiceManage.h"
#include "../WidgetView/CWidgetViewManage.h"
#include <memory>
//#include "../CService/CServiceGenerate/CServiceGenerate.h"
#include "CService/CServiceGenerate/CServiceGenerate.h"
#include "form.h"
#include <QProcess>
class CController : public IController
{
    SINGLETON(CController)
    Q_OBJECT
    CServiceManage* m_pServiceManage = nullptr;
    CWidgetViewManage* m_pWidgetViewManage = nullptr;
public:
    explicit CController(QObject *parent = nullptr);
    void initModule();
    void initServiceManage();
    void initWidgetViewManage();
    void initServiceGenerator();
    void initSlot();
    void registerService(IService* service,SERVICE_THREAD_ID serviceThreadId);
    void registerView(IWidgetView* widgetView);
    void startTimerHandle(int ms,QSharedPointer<CDataStreamBase> base);
signals:
};

#endif // CCONTROLLER_H
