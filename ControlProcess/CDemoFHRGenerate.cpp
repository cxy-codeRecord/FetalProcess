#include "CDemoFHRGenerate.h"
#include "../Common/Demo/DemoFetalHeartDataStructs.h"
CDemoFHRGenerate::CDemoFHRGenerate(QObject *parent) : QObject(parent),
    m_demoFetalHeartOneSize(sizeof(g_DemoFetalHeartOneData)/sizeof(int)),
    m_demoFetalHeartOneIndex(0),
    m_demoFetalHeartTwoSize(sizeof(g_DemoFetalHeartTwoData)/sizeof(int)),
    m_demoFetalHeartTwoIndex(0),
    m_demoFetalHeartThreeSize(sizeof(g_DemoFetalHeartThreeData)/sizeof(int)),
    m_demoFetalHeartThreeIndex(0)
{
   qDebug()<<"m_demoFetalHeartOneSize:"<<m_demoFetalHeartOneSize;
}

int CDemoFHRGenerate::getDemoFetalHeartOneData()
{
    if(m_demoFetalHeartOneIndex>=m_demoFetalHeartOneSize)
    {
        m_demoFetalHeartOneIndex = 0;
    }
    int data = g_DemoFetalHeartOneData[m_demoFetalHeartOneIndex];
    m_demoFetalHeartOneIndex++;
    return data;
}

int CDemoFHRGenerate::getDemoFetalHeartTwoData()
{
    if(m_demoFetalHeartTwoIndex>=m_demoFetalHeartTwoSize)
    {
        m_demoFetalHeartTwoIndex = 0;
    }
    int data = g_DemoFetalHeartTwoData[m_demoFetalHeartTwoIndex];
    m_demoFetalHeartTwoIndex++;
    return data;
}

int CDemoFHRGenerate::getDemoFetalHeartThreeData()
{
    if(m_demoFetalHeartThreeIndex>=m_demoFetalHeartThreeSize)
    {
        m_demoFetalHeartThreeIndex = 0;
    }
    int data = g_DemoFetalHeartThreeData[m_demoFetalHeartThreeIndex];
    m_demoFetalHeartThreeIndex++;
    return data;
}







