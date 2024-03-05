#ifndef CWIDGETVIEWMANAGE_H
#define CWIDGETVIEWMANAGE_H

#include <QObject>
#include "IWidgetView.h"
#include <QList>
#include "../Common/MyCommon.h"
#include "../Common/CDataStructs.h"
#include <QSharedPointer>
#include <QVector>
class CWidgetViewManage : public QObject
{
    SINGLETON(CWidgetViewManage)
    Q_OBJECT
public:
    explicit CWidgetViewManage(QObject *parent = nullptr);
    void initModule(){
        //qDebug()<<"m_vectorWidgetView "<<" begin";
        auto it = m_vectorWidgetView.begin();
        while(it!=m_vectorWidgetView.end())
        {
            //qDebug()<<"IWidgetView:"<<(*it)->getViewName()<<" begin";
            (*it)->initModule();
            //qDebug()<<"IWidgetView:"<<(*it)->getViewName()<<" end";
            it++;
        }
    };
protected:
    //QMap<QString,IWidgetView*>m_mapWidgetView;
    QVector<IWidgetView*> m_vectorWidgetView;
public:
    void registerWidgetView(IWidgetView* view);
public slots:
    void onRecvResponse(const QString funcName,const QSharedPointer<CDataStreamBase> responsePack);
signals:
    void signalRequestService(const QSharedPointer<CDataStreamBase>& pack);
    void signalRecvResponse(const QSharedPointer<CDataStreamBase> pack);
public slots:
};

#endif // CWIDGETVIEWMANAGE_H
