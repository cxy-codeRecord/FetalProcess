#ifndef CCPAXISTICKERTIMER_H
#define CCPAXISTICKERTIMER_H

#include <QObject>
#include "qcustomplot.h"
#include <QDateTime>

class CCPAxisTickerTimer : public QCPAxisTickerDateTime
{
  Q_GADGET
public:
    explicit CCPAxisTickerTimer();
protected:
    QString getTickLabel(double tick, const QLocale &locale, QChar formatChar, int precision);
    QVector<double> createTickVector(double tickStep, const QCPRange &range) Q_DECL_OVERRIDE;
};

#endif // CCPAXISTICKERTIMER_H
