#ifndef CTGVIEW_H
#define CTGVIEW_H

#include <QWidget>
#include <QWidget>
#include "qcustomplot.h"
#include "qcustomplot.h"
#include "CBackGround.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QGestureEvent>
#include <QTimer>
#include <QWheelEvent>
#include "CGrid.h"
#include "CTGState.h"
#include <QMainWindow>
#include "../Interface/WidgetView/CWidgetView.h"
class CTGView : public CWidgetView
{
    Q_OBJECT
public:
    explicit CTGView(QWidget *parent = nullptr);
    ~CTGView();
signals:
    void signalPrinterUnitState(int state);
protected:
    void init();
    void initSetup();
    void initXAxisTick();
    void initYAxisTick();
    void initGraph();
    void initTimer();
    void initBackGround();
    void initSlot();
    void initXAxis1Tick();
    void initXAxis2Tick();
    void initPixUnit();
    void initGrid();
    void initZoomStateYRange();
    void initModule();
    void getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase>data);
protected:
    double calculate1CM();
    double calculate2CM();
    double calculate3CM();
protected:
    void handleZoomState(CTGState::ZOOM_DIRECTION direction,QWheelEvent* e);
    void handleZoomState(CTGState::ZOOM_DIRECTION direction,double xPixelToCoord,double yPixelToCoord);
protected:
    void createTestData();
public:
    Q_INVOKABLE void handlePrinterUnitState(int state);
public slots:
    void timeoutHandle();
    void updateQuickCustomPlotUI();
    void limitXRangeChanged(const QCPRange &newRange, const QCPRange &oldRange);
    void limitYRangeChanged(const QCPRange &newRange, const QCPRange &oldRange);
    void mouseWheel(QWheelEvent* e);
    void mouseMove(QMouseEvent* e);
protected:
    QTimer m_timer;
protected:
    QCustomPlot* m_CustomPlot = nullptr;
    CBackGround* m_pCBackGround = nullptr;
    QCPGraph* m_FHR1Graph = nullptr;
    QCPGraph* m_FHR2Graph = nullptr;
    QCPGraph* m_FHR3Graph = nullptr;
    QCPGraph* m_FMGraph = nullptr;
    QCPGraph* m_TOCOGraph = nullptr;
    CGrid* m_Grid = nullptr;
protected:
    QColor m_FHR1LineColor = Qt::blue;
    QColor m_FHR2LineColor = Qt::yellow;
    QColor m_FHR3LineColor = Qt::green;
    QColor m_MHRLineColor = Qt::darkGreen;
    QColor m_TOCOLineColor = Qt::black;
    double m_1cmPixUnit = -1;
    double m_2cmPixUnit = -1;
    double m_3cmPixUnit = -1;
    double m_1cmRange = -1;
    double m_2cmRange = -1;
    double m_3cmRange = -1;
protected:
    QCPRange m_zoomState0YRange;
    QCPRange m_zoomState1YRange;
    QCPRange m_zoomState2YRange;
};

#endif // CTGVIEW_H
