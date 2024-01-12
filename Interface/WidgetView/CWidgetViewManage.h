#ifndef CWIDGETVIEWMANAGE_H
#define CWIDGETVIEWMANAGE_H

#include <QObject>
#include "IWidgetView.h"
#include <QList>
#include "../Common/MyCommon.h"
#include "../Common/CDataStructs.h"
#include <QSharedPointer>

class CWidgetViewManage : public QObject
{
    SINGLETON(CWidgetViewManage)
    Q_OBJECT
public:
    explicit CWidgetViewManage(QObject *parent = nullptr);
    void initModule(){};
protected:
    QMap<QString,IWidgetView*>m_mapWidgetView;
public:
    void registerWidgetView(IWidgetView* view);
public slots:
    //void slot_RecvResponse(const CDataStreamWrapped pack);
    void slot_RecvResponse(const QSharedPointer<CDataStreamBase> responsePack);
signals:
    void signal_RequestService(const QSharedPointer<CDataStreamBase>& pack);
    void signal_RecvResponse(const QSharedPointer<CDataStreamBase> pack);
public slots:
};

#endif // CWIDGETVIEWMANAGE_H
