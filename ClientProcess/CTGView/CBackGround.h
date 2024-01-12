#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include <QObject>
#include "qcustomplot.h"
#include<QVector>
class CBackGround : public QCPLayerable
{
    Q_OBJECT
public:
    struct Element
    {
        double upper;
        double lower;
        QColor color;
        Element(double lower,double upper,QColor color)
        {
            this->lower = lower;
            this->upper = upper;
            this->color = color;
        }
        Element()
        {

        }
    };
public:
    explicit CBackGround(QCustomPlot* plot);
    void draw(QCPPainter *painter);
    void addXAxis(QCPAxis* xAxis);
    void addYAxis(QCPAxis* yAxis);
    void applyAntialiasingHint(QCPPainter *painter, bool localAntialiased, QCP::AntialiasedElement overrideElement) const;
    void applyDefaultAntialiasingHint(QCPPainter *painter) const;
    void addElement(double lower,double upper,QColor color);
signals:
protected:
    QCPAxis* m_xAxis = nullptr;
    QCPAxis* m_yAxis = nullptr;
    QVector<Element>m_Elements;
};

#endif // CBACKGROUND_H
