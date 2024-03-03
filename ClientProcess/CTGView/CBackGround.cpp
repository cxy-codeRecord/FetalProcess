#include "CBackGround.h"
#include <QDebug>
#include <algorithm>
CBackGround::CBackGround(QCustomPlot* plot):QCPLayerable(plot)
{
//    addElement(0,100,(QColor(224,224,224))); //宫压0-100
//    addElement(100,160,QColor(0xff,0xf3,0xbf)); //胎心 50-110
//    addElement(160,210,QColor(0xde,0xff,0xd1));//胎心 110-160
//    addElement(210,260,QColor(0xff,0xf3,0xbf));//胎心 160-210
    addElement(0,100,(QColor(224,224,224))); //宫压0-100
    addElement(100,150,QColor(0xff,0xd7,0xbf)); //胎心 50-100
    addElement(150,160,QColor(0xff,0xf3,0xbf)); //胎心 100-110
    addElement(160,210,QColor(0xde,0xff,0xd1));//胎心 110-160
    addElement(210,230,QColor(0xff,0xf3,0xbf)); //胎心 160-180
    addElement(230,260,QColor(0xff,0xd7,0xbf));//胎心 180-210

}

void CBackGround::draw(QCPPainter *painter)
{
    //重写绘制背景色的函数，以下判断包含色块全显示，涉及两个色块的边界值的处理(比较麻烦)，已测试无误
        if(m_xAxis&&m_yAxis)
        {
            double lowerX = m_xAxis->range().lower;
            double upperX = m_xAxis->range().upper;
            double lowerY = (m_yAxis->range().lower);
            double upperY = (m_yAxis->range().upper);
            double minPX = m_xAxis->coordToPixel(lowerX);
            double maxPX = m_xAxis->coordToPixel(upperX);
            double minPY = m_yAxis->coordToPixel(lowerY);
            double maxPY = m_yAxis->coordToPixel(upperY);
            int len = m_Elements.length();
            if(len<=0)return;
            if(upperY>m_Elements[len-1].upper)
            {
                double eleUpper = m_Elements[len-1].upper;
                double eleLower = m_Elements[len-1].lower;
                double y1 = m_yAxis->coordToPixel(eleUpper);
                double y2 = m_yAxis->coordToPixel(eleLower);
                painter->setBrush(QBrush(m_Elements[len-1].color));
                painter->setPen(QPen(m_Elements[len-1].color));
                painter->drawRect(QRect(QPoint(minPX,maxPY),QPoint(maxPX,y1)));
            }
            if(lowerY<m_Elements[0].lower)
            {
                double eleUpper = m_Elements[0].upper;
                double eleLower = m_Elements[0].lower;
                double y1 = m_yAxis->coordToPixel(eleUpper);
                double y2 = m_yAxis->coordToPixel(eleLower);
                painter->setBrush(QBrush(m_Elements[0].color));
                painter->setPen(QPen(m_Elements[0].color));
                painter->drawRect(QRect(QPoint(minPX,y2),QPoint(maxPX,minPY)));
            }
            for(int i=0;i<len;i++)
            {
                double eleUpper = m_Elements[i].upper;
                double eleLower = m_Elements[i].lower;
                double y1 = m_yAxis->coordToPixel(eleUpper);
                double y2 = m_yAxis->coordToPixel(eleLower);
                if((eleLower>=lowerY)&&(eleUpper<=upperY))
                {
                    painter->setBrush(QBrush(m_Elements[i].color));
                    painter->setPen(QPen(m_Elements[i].color));
                    painter->drawRect(QRect(QPoint(minPX,y1),QPoint(maxPX,y2)));
                }
                else if((eleUpper>=upperY)&&(upperY>=eleLower)&&(eleUpper>=lowerY)&&(eleLower>=lowerY))
                {
                    painter->setBrush(QBrush(m_Elements[i].color));
                    painter->setPen(QPen(m_Elements[i].color));
                    painter->drawRect(QRect(QPoint(minPX,maxPY),QPoint(maxPX,y2)));
                }
                else if((eleUpper>=lowerY)&&(eleLower<=lowerY))
                {
                    painter->setBrush(QBrush(m_Elements[i].color));
                    painter->setPen(QPen(m_Elements[i].color));
                    painter->drawRect(QRect(QPoint(minPX,y1),QPoint(maxPX,minPY)));
                }
            }
        }
}

void CBackGround::addXAxis(QCPAxis *xAxis)
{
    m_xAxis = xAxis;
}

void CBackGround::addYAxis(QCPAxis *yAxis)
{
    m_yAxis = yAxis;
}

void CBackGround::applyAntialiasingHint(QCPPainter *painter, bool localAntialiased, QCP::AntialiasedElement overrideElement) const
{
    painter->setAntialiasing(true);
}

void CBackGround::applyDefaultAntialiasingHint(QCPPainter *painter) const
{
    painter->setAntialiasing(true);
}

//绘制背景色添加不同颜色的色块
void CBackGround::addElement(double lower, double upper, QColor color)
{
    CBackGround::Element element(lower,upper,color);
    m_Elements.push_back(element);
}
