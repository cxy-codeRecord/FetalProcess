#include "CCPAxisTickerTimer.h"
#include "CTGState.h"
CCPAxisTickerTimer::CCPAxisTickerTimer()
{

}

QString CCPAxisTickerTimer::getTickLabel(double tick, const QLocale &locale, QChar formatChar, int precision)
{
    Q_UNUSED(precision)
    Q_UNUSED(formatChar)
    Q_UNUSED(locale)
    static QDateTime orignalDateTime = QDateTime::currentDateTime();
    int points = CTGState::getPrinterUnitTimeTickPoints();
    int timeTickSpacing = CTGState::getPrinterTimeTickSpacing();
    QString result;
    if(tick<0)
    {
        return result;
    }
    if((int)tick%points==0)
    {
        int offsetValue = (int)tick/points;
        QDateTime bakDateTime = orignalDateTime;
        QDateTime currentDateTime = bakDateTime.addSecs(offsetValue*60*timeTickSpacing);
        result = currentDateTime.toString("yyyy:MM:dd:hh:mm:ss");
    }
    //result = "";
    return result;
}

QVector<double> CCPAxisTickerTimer::createTickVector(double tickStep, const QCPRange &range)
{
    int newXRangeUpper = (int)std::floor(range.upper);
    int newXRangeLower = (int)std::ceil(range.lower);
    int points = CTGState::getPrinterUnitTimeTickPoints();
    int space = newXRangeLower/points;
    int value = space*points;
    QVector<double> xTickVector;
//    int points = CTGState::getPrinterUnitSubTickPoints();
    for(int i=value;i<newXRangeUpper;i+=points)
    {
        xTickVector.append(i);
    }
    return xTickVector;
}
