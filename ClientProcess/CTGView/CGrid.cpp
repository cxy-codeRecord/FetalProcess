#include "CGrid.h"
#include <cmath>
#include <algorithm>
#include <QBrush>
#include <cmath>

CGrid::CGrid(QCustomPlot *parent)
    : QCPLayerable{parent}
{
    initSettingYTick();
    initFHRTextElement();
    initTOCOTextElement();
}


void CGrid::initSettingYTick()
{
    double max_value = 300;
    double per_value = 20;
    for(int i=0;i<=max_value;i+=per_value)
    {
        m_settingYTick.append(i);
    }
}

void CGrid::initFHRTextElement()
{
    QVector<QColor> vector;
    vector.append(QColor(0xff,0xf3,0xbf));
    QVector<QColor> vector2;
    vector2.append(QColor(0xff,0xf3,0xbf));
    vector2.append(QColor(0xde,0xff,0xd1));
    QVector<QColor> vector3;
    vector3.append(QColor(0xde,0xff,0xd1));
    QVector<QColor> vector4;
    vector4.append(QColor(0xde,0xff,0xd1));
    vector4.append(QColor(0xff,0xf3,0xbf));
    QVector<QColor> vector5;
    vector5.append(QColor(0xff,0xf3,0xbf));
    QVector<QColor> vector6;
    vector6.append(QColor(0xff,0xf3,0xbf));
    vector6.append(QColor(224,224,224));
    addFHRTextElement(290,"240",vector);
    addFHRTextElement(270,"220",vector);
    addFHRTextElement(250,"200",vector);
    addFHRTextElement(230,"180",vector);
    addFHRTextElement(210,"160",vector2);
    addFHRTextElement(190,"140",vector3);
    addFHRTextElement(170,"120",vector3);
    addFHRTextElement(150,"100",vector5);
    addFHRTextElement(130," 80",vector5);
    addFHRTextElement(110," 60",vector5);
    addFHRTextElement(100," HR",vector6);
}

void CGrid::initTOCOTextElement()
{
    QVector<QColor> vector;
    vector.append(QColor(0xff,0xf3,0xbf));
    vector.append(QColor(224,224,224));
    addTOCOTextElement(100,"100",vector);
    QVector<QColor> vector2;
    vector2.append(QColor(224,224,224));
    addTOCOTextElement(80," 80",vector2);
    addTOCOTextElement(60," 60",vector2);
    addTOCOTextElement(40," 40",vector2);
    addTOCOTextElement(20," 20",vector2);
    addTOCOTextElement(0," UA",vector2);
}


void CGrid::addXAxis(QCPAxis *xAxis)
{
    m_xAxis = xAxis;
}

void CGrid::addYAxis(QCPAxis *yAxis)
{
    m_yAxis = yAxis;
}

void CGrid::applyAntialiasingHint(QCPPainter *painter, bool localAntialiased, QCP::AntialiasedElement overrideElement) const
{
    painter->setAntialiasing(true);
}

void CGrid::applyDefaultAntialiasingHint(QCPPainter *painter) const
{
    painter->setAntialiasing(true);
}

void CGrid::draw(QCPPainter *painter)
{
    if((m_xAxis)&&(m_yAxis))
    {
        QCPRange xRange = m_xAxis->range();
        double xRangeUpper = xRange.upper;
        double xRangeLower = xRange.lower;
        QVector<double> xTickVector;
        QVector<double> xSubTickVector;
        double tickValue = 0;
        int newXRangeUpper = (int)std::floor(xRangeUpper);
        int newXRangeLower = (int)std::ceil(xRangeLower);
        int printerUnitPoints = CTGState::getPrinterUnitPoints();
        int space = newXRangeLower/printerUnitPoints;
        int value = space*printerUnitPoints;
        for(int i=value;i<newXRangeUpper;i+=printerUnitPoints)
        {
            //if((xPos>=m_xAxis->axisRect()->left()+10)&&(xPos<=m_xAxis->axisRect()->right()-10))
            //{
            xTickVector.append(i);
            tickValue = i;
            handleXSubTickValue(xSubTickVector,tickValue);
            //}
        }
        double pos = 0;
        QPen penSolid(QColor(200,200,200), 0, Qt::SolidLine);
        for(int i=0;i<xTickVector.length();i++)
        {
            pos = m_xAxis->coordToPixel(xTickVector[i]);
            if((pos>=m_xAxis->axisRect()->left()+10)&&(pos<=m_xAxis->axisRect()->right()-10))
            {
            painter->setPen(penSolid);
            painter->drawLine(QLineF(pos,m_xAxis->axisRect()->bottom(),pos,m_xAxis->axisRect()->top()));
            }
        }
        QPen penDot(QColor(200,200,200),0,Qt::DotLine);
        for(int i=0;i<xSubTickVector.length();i++)
        {
            pos = m_xAxis->coordToPixel(xSubTickVector[i]);
            if((pos>=m_xAxis->axisRect()->left()+10)&&(pos<=m_xAxis->axisRect()->right()-10))
            {
            painter->setPen(penDot);
            painter->drawLine(QLineF(pos,m_xAxis->axisRect()->bottom(),pos,m_xAxis->axisRect()->top()));
            }
        }
        QVector<double> yTickVector;
        QVector<double> ySubTickVector;
        QCPRange yRange = m_yAxis->range();
        double yRangeUpper = yRange.upper;
        double yRangeLower = yRange.lower;
        auto startYRange = std::lower_bound(m_settingYTick.begin(),m_settingYTick.end(),yRangeLower);
        auto endYRange = std::upper_bound(m_settingYTick.begin(),m_settingYTick.end(),yRangeUpper);
        for(auto it=startYRange;it!=endYRange;it++)
        {
            yTickVector.append(*it);
            ySubTickVector.append(*it-10);

        }
        for(int i=0;i<yTickVector.length();i++)
        {
            pos = m_yAxis->coordToPixel(yTickVector[i]);
            painter->setPen(penSolid);
            painter->drawLine(QLineF(m_yAxis->axisRect()->left(),pos,m_yAxis->axisRect()->right(),pos));
        }
        for(int i=0;i<ySubTickVector.length();i++)
        {
            pos = m_yAxis->coordToPixel(ySubTickVector[i]);
            painter->setPen(penDot);
            painter->drawLine(QLineF(m_yAxis->axisRect()->left(),pos,m_yAxis->axisRect()->right(),pos));
        }

        parseFHRTextElement(xTickVector,yTickVector,painter);
        parseTOCOTextElement(xTickVector,yTickVector,painter);
    }
}

void CGrid::addFHRTextElement(double key, QString value, QVector<QColor> colors)
{
    TextElement e;
    e.value = value;
    e.colors = colors;
    m_FHRTextElments.insert(key,e);
}

void CGrid::addTOCOTextElement(double key, QString value, QVector<QColor> colors)
{
    TextElement e;
    e.value = value;
    e.colors = colors;
    m_TOCOTextElments.insert(key,e);
}

void CGrid::parseFHRTextElement(const QVector<double> &xTickVector, const QVector<double> &yTickVector, QCPPainter *painter)
{

    int len = yTickVector.length();
    if(len<=1)return;
    double yLowerTick = yTickVector[0];
    double yUpperTick = yTickVector[len-1];
    auto start = m_FHRTextElments.lowerBound(yLowerTick);
    auto end = m_FHRTextElments.upperBound(yUpperTick);
    double key;
    QString value;
    QVector<QColor>colors;
    for(int i=0;i<xTickVector.length();i++)
    {
        if(((int)xTickVector[i]>=0)&&((int)xTickVector[i]%(240*10)==0))
        {
            double xPos = m_xAxis->coordToPixel(xTickVector[i]);
            if((xPos>=m_xAxis->axisRect()->left()+10)&&(xPos<=m_xAxis->axisRect()->right()-10))
            {
            for(auto it=start;it!=end;it++)
            {
                key = it.key();
                value = it.value().value;
                colors = it.value().colors;
                double yPos = m_yAxis->coordToPixel(key);
                if((yPos>=m_yAxis->axisRect()->top()+10)&&(yPos<=m_yAxis->axisRect()->bottom()-10))
                {
                if(colors.length()==1)
                {
                    painter->setBrush(colors[0]);
                    QPen pen(Qt::NoPen);
                    painter->setPen(pen);
                    painter->drawRect(QRect(QPoint(xPos-10,yPos-10),QPoint(xPos+10,yPos+10)));
                    QPen pen2(QColor(200,200,200), 0, Qt::SolidLine);
                    painter->setPen(pen2);
                    painter->drawText(xPos-10,yPos+5,value);
                }
                else if(colors.length()==2)
                {
                    QPen pen(Qt::NoPen);
                    painter->setPen(pen);
                    painter->setBrush(colors[0]);
                    painter->drawRect(QRect(QPoint(xPos-10,yPos-10),QPoint(xPos+10,yPos)));
                    painter->setBrush(colors[1]);
                    painter->drawRect(QRect(QPoint(xPos-10,yPos),QPoint(xPos+10,yPos+10)));
                    QPen pen2(QColor(200,200,200), 0, Qt::SolidLine);
                    painter->setPen(pen2);
                    painter->drawText(xPos-10,yPos+5,value);
                }
                }
            }
            }
        }
    }
}

void CGrid::parseTOCOTextElement(const QVector<double> &xTickVector, const QVector<double> &yTickVector, QCPPainter *painter)
{
    int len = yTickVector.length();
    if(len<=1)return;
    double yLowerTick = yTickVector[0];
    double yUpperTick = yTickVector[len-1];
    auto start = m_TOCOTextElments.lowerBound(yLowerTick);
    auto end = m_TOCOTextElments.upperBound(yUpperTick);
    double key;
    QString value;
    QVector<QColor>colors;
    for(int i=0;i<xTickVector.length();i++)
    {
        if(((int)xTickVector[i]>=0)&&((int)(xTickVector[i])%(1200)==0)&&((int)(xTickVector[i])%(2400)!=0))
        {
            double xPos = m_xAxis->coordToPixel(xTickVector[i]);
            if((xPos>=m_xAxis->axisRect()->left()+10)&&(xPos<=m_xAxis->axisRect()->right()-10))
            {
            for(auto it=start;it!=end;it++)
            {
                key = it.key();
                value = it.value().value;
                colors = it.value().colors;
                double yPos = m_yAxis->coordToPixel(key);
                if((yPos>=m_yAxis->axisRect()->top()+10)&&(yPos<=m_yAxis->axisRect()->bottom()-10))
                {
                    if(colors.length()==1)
                    {
                        painter->setBrush(colors[0]);
                        QPen pen(Qt::NoPen);
                        painter->setPen(pen);
                        painter->drawRect(QRect(QPoint(xPos-10,yPos-10),QPoint(xPos+10,yPos+10)));
                        QPen pen2(QColor(200,200,200), 0, Qt::SolidLine);
                        painter->setPen(pen2);
                        painter->drawText(xPos-10,yPos+5,value);
                    }
                    else if(colors.length()==2)
                    {
                        QPen pen(Qt::NoPen);
                        painter->setPen(pen);
                        painter->setBrush(colors[0]);
                        painter->drawRect(QRect(QPoint(xPos-10,yPos-10),QPoint(xPos+10,yPos)));
                        painter->setBrush(colors[1]);
                        painter->drawRect(QRect(QPoint(xPos-10,yPos),QPoint(xPos+10,yPos+10)));
                        QPen pen2(QColor(200,200,200), 0, Qt::SolidLine);
                        painter->setPen(pen2);
                        painter->drawText(xPos-10,yPos+5,value);
                    }
                }
            }
            }
        }
    }
}

void CGrid::handlePrinterUnitState(int state)
{
    CTGState::PRINTER_UNIT_STATE printState = (CTGState::PRINTER_UNIT_STATE)state;
    switch(printState)
    {
    case CTGState::PRINTER_UNIT_STATE::ONE_CM_MINUTER:
    {
        CTGState::setPrinterUnitState(CTGState::PRINTER_UNIT_STATE::ONE_CM_MINUTER);
        CTGState::setPrinterUnitSubTickPoints(CTGState::PRINTER_UNIT_SUBTICK_POINTS::ONE_CM_SUBTICK_POINTS);
        break;
    }
    case CTGState::PRINTER_UNIT_STATE::TWO_CM_MINUTER:
    {
        CTGState::setPrinterUnitState(CTGState::PRINTER_UNIT_STATE::TWO_CM_MINUTER);
        CTGState::setPrinterUnitSubTickPoints(CTGState::PRINTER_UNIT_SUBTICK_POINTS::TWO_CM_SUBTICK_POINTS);
        break;
    }
    case CTGState::PRINTER_UNIT_STATE::THREE_CM_MINUTER:
    {
        CTGState::setPrinterUnitState(CTGState::PRINTER_UNIT_STATE::ONE_CM_MINUTER);
        CTGState::setPrinterUnitSubTickPoints(CTGState::PRINTER_UNIT_SUBTICK_POINTS::TWO_CM_SUBTICK_POINTS);
        break;
    }
    default:break;
    }
}

void CGrid::handleXSubTickValue(QVector<double> &xSubTickVector, const double& TickValue)
{
    int printerUnitSubTickpoints = CTGState::getPrinterUnitSubTickPoints();
    int count = (int)TickValue/printerUnitSubTickpoints;
    for(int i=1;i<count;i++)
    {
        xSubTickVector.append(TickValue-i*(int)printerUnitSubTickpoints);
    }
}
