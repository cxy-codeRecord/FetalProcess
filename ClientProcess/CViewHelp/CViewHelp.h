#ifndef CVIEWHELP_H
#define CVIEWHELP_H

#include <QObject>
#include "../Common/MyCommon.h"
class CViewHelp : public QObject
{
    Q_OBJECT
    SINGLETON(CViewHelp)
protected:
    explicit CViewHelp(QObject *parent = nullptr);
signals:
    void signalShowDealOnGoingRecordDialog();
    void signalShowDealPauseRecordDialog();

};

#endif // CVIEWHELP_H
