#ifndef CGRID_H
#define CGRID_H

#include <QObject>
#include "qcustomplot.h"
#include <QVector>
#include <QColor>
#include "CTGState.h"
class CGrid : public QCPLayerable
{
    Q_OBJECT
    struct TextElement
    {
        QString value;
        QVector<QColor> colors;
    };
public:
    explicit CGrid(QCustomPlot *parent = nullptr);
    void initSettingYTick();
    void initFHRTextElement();
    void initTOCOTextElement();
signals:
public:
    void addXAxis(QCPAxis* xAxis);
    void addYAxis(QCPAxis* yAxis);
    void applyAntialiasingHint(QCPPainter *painter, bool localAntialiased, QCP::AntialiasedElement overrideElement) const;
    void applyDefaultAntialiasingHint(QCPPainter *painter) const;
    void draw(QCPPainter *painter);
protected:
    QCPAxis* m_xAxis = nullptr;
    QCPAxis* m_yAxis = nullptr;
    QVector<double> m_settingXTick;
    QVector<double> m_settingYTick;
    QMap<double,TextElement> m_TextElments;
    QMap<double,TextElement> m_FHRTextElments;
    QMap<double,TextElement> m_TOCOTextElments;
protected:
    void addFHRTextElement(double key,QString value,QVector<QColor>colors);
    void addTOCOTextElement(double key,QString value,QVector<QColor>colors);
    void parseFHRTextElement(const QVector<double>&xTickVector,const QVector<double>&yTickVector,QCPPainter *painter);
    void parseTOCOTextElement(const QVector<double>&xTickVector,const QVector<double>&yTickVector,QCPPainter *painter);
    void handleXSubTickValue(QVector<double>&xSubTickVector,const double& TickValue);
public slots:
    void handlePrinterUnitState(int state);



};

#endif // CGRID_H
