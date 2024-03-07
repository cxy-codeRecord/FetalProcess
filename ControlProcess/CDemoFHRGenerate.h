#ifndef CDEMOFHRGENERATE_H
#define CDEMOFHRGENERATE_H
#include "../Common/CDataStructs.h"
#include <QObject>
extern int g_DemoFetalHeartOneData[];
extern int g_DemoFetalHeartTwoData[];
extern int g_DemoFetalThreeTwoData[];
class CDemoFHRGenerate : public QObject
{
    Q_OBJECT
protected:
    int m_demoFetalHeartOneSize;
    int m_demoFetalHeartOneIndex;
    int m_demoFetalHeartTwoSize;
    int m_demoFetalHeartTwoIndex;
    int m_demoFetalHeartThreeSize;
    int m_demoFetalHeartThreeIndex;
public:
    explicit CDemoFHRGenerate(QObject *parent = nullptr);
    void resetDemoFetalHeartIndex();
    int getDemoFetalHeartOneData();
    int getDemoFetalHeartTwoData();
    int getDemoFetalHeartThreeData();
signals:

};
#endif // CDEMOFHRGENERATE_H
