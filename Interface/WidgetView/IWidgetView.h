#ifndef IWIDGETVIEW_H
#define IWIDGETVIEW_H
#include <QWidget>
#include <QMap>
#include "../Common/CDataStructs.h"
#include "../Common/MyCommon.h"
#include <functional>
#include <QSharedPointer>
class IWidgetView : public QWidget
{
    Q_OBJECT
protected:
    QMap<QString,function<void(QSharedPointer<CDataStreamBase>)>> m_mapRecvResponseHandle;
    QString m_viewName;
public:
    explicit IWidgetView(const QString& viewName,QWidget *parent = nullptr);
    virtual void initModule() = 0;
    void requestService(const QSharedPointer<CDataStreamBase>& pack);
    void registerRecvResponseHandle(const QString funcName,function<void(QSharedPointer<CDataStreamBase>)>func);
    QString getViewName();
    bool getRecvResponseHandle(const QString& funcName,function<void(QSharedPointer<CDataStreamBase>)>& handleFunc);
signals:
    void signalRequestService(const QSharedPointer<CDataStreamBase>& pack);
    void signalStartTimerHandle(const QSharedPointer<CDataStreamBase>& pack);
protected slots:
    void onRecvResponseHandle(const QString funcName,const QSharedPointer<CDataStreamBase> data);
};

#endif // IWIDGETVIEW_H
