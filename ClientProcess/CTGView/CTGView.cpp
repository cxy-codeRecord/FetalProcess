#include "CTGView.h"
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <math.h>
#include "CCPAxisTickerTimer.h"
#include <cmath>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
//#include "../Common/MyCommon.h"
#include "../../Common/Service/ServiceCommon.h"
#include "../../Common/View/ViewCommon.h"
CTGView::CTGView(QWidget *parent) : CWidgetView(CTGVIEW_NAME,parent)
{
    init();
}

CTGView::~CTGView()
{

}



void CTGView::init()
{
    m_CustomPlot = new QCustomPlot(this);
    m_CustomPlot->move(0,0);
    QHBoxLayout* hb = new QHBoxLayout(this);
    hb->setMargin(0);
    hb->setSpacing(0);
    hb->addWidget(m_CustomPlot);
    initGraph();
    initBackGround();
    initXAxisTick();
    initYAxisTick();
    initSetup();
    initTimer();
    initGrid();
    initZoomStateYRange();
    initSlot();
    handlePrinterUnitState(0);
    m_CustomPlot->setNoAntialiasingOnDrag(true);
}



void CTGView::initSetup()
{
    m_CustomPlot->setInteractions( QCP::iRangeDrag);
}

void CTGView::initXAxisTick()
{
    initXAxis1Tick();
    initXAxis2Tick();
}

void CTGView::initYAxisTick()
{
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    m_CustomPlot->yAxis->setTicker(textTicker);
    m_CustomPlot->yAxis->grid()->setSubGridVisible(false);
    m_CustomPlot->yAxis->setSubTicks(false);;
    m_CustomPlot->yAxis->setRange(-40,280);
    m_CustomPlot->yAxis->setOffset(0);
    m_CustomPlot->yAxis->setPadding(0);
    QCPAxisRect * axisRect = m_CustomPlot->axisRect();
    axisRect->setMinimumMargins(QMargins(0,0,0,0));
}

void CTGView::initGraph()
{
    m_FHR1Graph = m_CustomPlot->addGraph();
    m_FHR2Graph = m_CustomPlot->addGraph();
    m_FHR3Graph = m_CustomPlot->addGraph();
    m_FMGraph = m_CustomPlot->addGraph();
    m_TOCOGraph = m_CustomPlot->addGraph();
    QPen fhr1Pen;
    QPen fhr2Pen;
    QPen fhr3Pen;
    QPen mhrPen;
    QPen tocoPen;
    fhr1Pen.setBrush(QBrush(m_FHR1LineColor));
    fhr2Pen.setBrush(QBrush(m_FHR2LineColor));
    fhr3Pen.setBrush(QBrush(m_FHR3LineColor));
    mhrPen.setBrush(QBrush(m_MHRLineColor));
    tocoPen.setBrush(QBrush(m_TOCOLineColor));
    fhr1Pen.setWidth(1);
    fhr2Pen.setWidth(1);
    fhr3Pen.setWidth(1);
    mhrPen.setWidth(1);
    tocoPen.setWidth(1);
    m_FHR1Graph->setPen(fhr1Pen);
    m_FHR2Graph->setPen(fhr2Pen);
    m_FHR3Graph->setPen(fhr3Pen);
    m_FMGraph->setPen(mhrPen);
    m_TOCOGraph->setPen(tocoPen);
}

void CTGView::initTimer()
{
    m_timer.start(200);
}

void CTGView::initBackGround()
{
    //初始化和添加背景色的图层
    m_pCBackGround = new CBackGround(m_CustomPlot);
    m_pCBackGround->addXAxis(m_CustomPlot->xAxis);
    m_pCBackGround->addYAxis(m_CustomPlot->yAxis);
    m_pCBackGround->setLayer("background");
    //m_CustomPlot->setBackground(Qt::transparent);
    //m_CustomPlot->initBackgroundBrush(Qt::NoBrush);//屏蔽原来的画布背景色绘制，不然会产生性能损耗，影响拖拽
}

void CTGView::initSlot()
{
    connect(m_CustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_CustomPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(m_CustomPlot->yAxis, SIGNAL(rangeChanged(const QCPRange&,const QCPRange&)), this, SLOT(limitYRangeChanged(const QCPRange&,const QCPRange&)));
    connect(&m_timer,&QTimer::timeout,this,&CTGView::timeoutHandle);
    connect(m_CustomPlot,&QCustomPlot::mouseWheel,this,&CTGView::mouseWheel);
    connect(this,&CTGView::signalPrinterUnitState,m_Grid,&CGrid::handlePrinterUnitState);
}

void CTGView::initXAxis1Tick()
{
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    m_CustomPlot->xAxis->setTicker(textTicker);
    m_CustomPlot->xAxis->setTickLabels(true);
    m_CustomPlot->xAxis->setSubTicks(false);
}

void CTGView::initXAxis2Tick()
{
    QSharedPointer<QCPAxisTickerDateTime> textTicker(new CCPAxisTickerTimer);
    m_CustomPlot->xAxis2->setTicker(textTicker);
    m_CustomPlot->xAxis2->setTickLabels(true);
    m_CustomPlot->xAxis2->grid()->setSubGridVisible(true);
    m_CustomPlot->xAxis2->setSubTicks(false);
    m_CustomPlot->xAxis2->setVisible(true);
    m_CustomPlot->xAxis2->setRange(m_CustomPlot->xAxis->range());
    m_CustomPlot->xAxis2->setRangeReversed(m_CustomPlot->xAxis->rangeReversed());
    m_CustomPlot->xAxis2->setScaleType(m_CustomPlot->xAxis->scaleType());
}



void CTGView::initPixUnit()
{
    m_1cmPixUnit = calculate1CM();
    m_2cmPixUnit = calculate2CM();
    m_3cmPixUnit = calculate3CM();
}

void CTGView::initGrid()
{
    m_Grid = new CGrid(m_CustomPlot);
    m_Grid->addXAxis(m_CustomPlot->xAxis);
    m_Grid->addYAxis(m_CustomPlot->yAxis);
    m_Grid->setLayer("grid");
}

void CTGView::initZoomStateYRange()
{
    m_zoomState1YRange.upper = 280;
    m_zoomState1YRange.lower = -40;
    m_zoomState2YRange.upper = 320;
    m_zoomState2YRange.lower = -80;
}

void CTGView::initModule()
{
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_GET_FETAL_HEART_DATA),bind(&CTGView::getFetalHeartDataRecvHandle,this,std::placeholders::_1));
    registerRecvResponseHandle(DEF_RECV_RESPONSE_FUNC_NAME(SERVICE_FUNC_CONTROLLER_RECORD),bind(&CTGView::controllerRecordRecvHandle,this,std::placeholders::_1));
}

void CTGView::clearGraphData()
{
    m_FHR1Graph->data().data()->clear();
    m_FHR2Graph->data().data()->clear();
    m_FHR3Graph->data().data()->clear();
    m_FMGraph->data().data()->clear();
    m_TOCOGraph->data().data()->clear();
    m_fetalDataIndex = 0;
}

void CTGView::getFetalHeartDataRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    CDataStream<CFetalHeartData>* ptr = data->toDataStream<CDataStream<CFetalHeartData>>();
    if(ptr)
    {
        int heartOne = ptr->data.fetalHeartOne + FHR_YAXIS_OFFSET;
        int heartTwo = ptr->data.fetalHeartTwo + FHR_YAXIS_OFFSET;
        int heartThree = ptr->data.fetalHeartThree + FHR_YAXIS_OFFSET;
        m_FHR1Graph->addData(m_fetalDataIndex,double(heartOne));
        m_FHR2Graph->addData(m_fetalDataIndex,double(heartTwo));
        m_FHR3Graph->addData(m_fetalDataIndex,double(heartThree));
    }
    m_fetalDataIndex++;
}

void CTGView::controllerRecordRecvHandle(QSharedPointer<CDataStreamBase> data)
{
    if(!data.isNull())
    {
        CDataStream<CRecordState>* ptr = data->toDataStream<CDataStream<CRecordState>>();
        if(ptr)
        {
            CRecordState currentState = ptr->data;
            m_recordState = currentState;
            switch (m_recordState)
            {
            case CRecordState::IDLE_STATE:
            {
                clearGraphData();
                m_timer.stop();
                break;
            }
            case CRecordState::ONGOING_STATE:
            {
                m_timer.start();
                break;
            }
            case CRecordState::PAUSE_STATE:
            {
                m_timer.stop();
                break;
            }
            }
        }
    }
}


double CTGView::calculate1CM()
{
    QRect geometry = QGuiApplication::primaryScreen()->geometry();
    QSizeF physicalSize = QGuiApplication::primaryScreen()->physicalSize();
    double mmWidth  = physicalSize.width()/10;//标准是以毫米为单位，所以要除以10
    double pixWidth = geometry.width();
    double per = pixWidth/mmWidth;
    return per;
}

double CTGView::calculate2CM()
{
    double ret = calculate1CM()*2;
    return ret;
}

double CTGView::calculate3CM()
{
    double ret = calculate1CM()*3;
    return ret;
}


void CTGView::updateQuickCustomPlotUI()
{
    //刷新qml的chart
    update();
    if((m_1cmPixUnit==-1)||(m_2cmPixUnit==-1)||(m_3cmPixUnit==-1))
    {
        QCPAxisRect * rect = m_CustomPlot->xAxis->axisRect();
        if(rect->width()>30)
        {
            initPixUnit();
            int axisWidth = rect->width();
            m_1cmRange= axisWidth/(m_1cmPixUnit)*240;
            m_2cmRange= axisWidth/(m_2cmPixUnit)*240;
            m_3cmRange= axisWidth/(m_3cmPixUnit)*240;
            m_CustomPlot->xAxis->setRange(0,m_3cmRange);
        }
    }
}

void CTGView::limitXRangeChanged(const QCPRange &newRange, const QCPRange &oldRange)
{
}

void CTGView::limitYRangeChanged(const QCPRange &newRange, const QCPRange &oldRange)
{
    double newUpperRangae = newRange.upper;
    double newLowerRangae = newRange.lower;
    CTGState::ZOOM_STATE state = CTGState::getZoomState();
    if(state==CTGState::ZOOM_STATE::ZOOM_STATE1)
    {
        if((newUpperRangae>m_zoomState1YRange.upper)||(newLowerRangae<m_zoomState1YRange.lower))
        {
            m_CustomPlot->yAxis->setRange(oldRange);
        }
    }
    else if(state==CTGState::ZOOM_STATE::ZOOM_STATE2)
    {
        if((newUpperRangae>m_zoomState2YRange.upper)||(newLowerRangae<m_zoomState2YRange.lower))
        {
            m_CustomPlot->yAxis->setRange(oldRange);
        }
    }
}

void CTGView::mouseWheel(QWheelEvent *e)
{
    const double delta = e->angleDelta().y()/120;
    if(delta>0)
    {
        handleZoomState(CTGState::ZOOM_DIRECTION::ZOOM_IN,e);
    }
    else if(delta<0)
    {
        handleZoomState(CTGState::ZOOM_DIRECTION::ZOOM_OUT,e);
    }
}

void CTGView::mouseMove(QMouseEvent *e)
{
    Q_UNUSED(e);
    CTGState::ZOOM_STATE state = CTGState::getZoomState();
    if(state == CTGState::ZOOM_STATE1)
    {
        m_CustomPlot->yAxis->setRange(m_zoomState1YRange);
    }
    else if(state == CTGState::ZOOM_STATE2)
    {
        m_CustomPlot->yAxis->setRange(m_zoomState2YRange);
    }
}

void CTGView::handlePrinterUnitState(int state)
{
    emit signalPrinterUnitState(state);
    CTGState::PRINTER_UNIT_STATE printerUnitState = (CTGState::PRINTER_UNIT_STATE)state;
    initXAxis2Tick();
    QCPRange range = m_CustomPlot->xAxis->range();
    double lower = range.lower;
    lower = std::ceil(lower);
    double distance = 0;
    switch(printerUnitState)
    {
    case CTGState::PRINTER_UNIT_STATE::ONE_CM_MINUTER:
    {
        distance = m_1cmRange;
        CTGState::setPrinterUnitTimeTickPoints(CTGState::PRINTER_UNIT_TIMETICK_POINTS::ONE_CM_TIMETICK_POINTS);
        CTGState::setPrinterUnitTimeTickSpacing(CTGState::PRINTER_TIMETICK_SPACING::ONE_CM_TIMETICK_SPACING);
        break;
    }
    case CTGState::PRINTER_UNIT_STATE::TWO_CM_MINUTER:
    {
        distance = m_2cmRange;
        CTGState::setPrinterUnitTimeTickPoints(CTGState::PRINTER_UNIT_TIMETICK_POINTS::TWO_CM_TIMETICK_POINTS);
        CTGState::setPrinterUnitTimeTickSpacing(CTGState::PRINTER_TIMETICK_SPACING::TWO_CM_TIMETICK_SPACING);
        break;
    }
    case CTGState::PRINTER_UNIT_STATE::THREE_CM_MINUTER:
    {
        distance = m_3cmRange;
        CTGState::setPrinterUnitTimeTickPoints(CTGState::PRINTER_UNIT_TIMETICK_POINTS::THREE_CM_TIMETICK_POINTS);
        CTGState::setPrinterUnitTimeTickSpacing(CTGState::PRINTER_TIMETICK_SPACING::THREE_CM_TIMETICK_SPACING);
        break;
    }
    default:break;
    }
    CTGState::setPrinterUnitState(printerUnitState);
    CTGState::setZoomState(CTGState::ZOOM_STATE1);
    m_CustomPlot->xAxis->setRange(lower,lower+distance);
    m_CustomPlot->yAxis->setRange(m_zoomState1YRange);

}

void CTGView::handleZoomState(CTGState::ZOOM_DIRECTION direction,QWheelEvent* e)
{
    QPoint globalPoint = e->globalPos();
    QPoint widgetPoint = m_CustomPlot->mapFromGlobal(globalPoint);
    double xPixelToCoord = m_CustomPlot->xAxis->pixelToCoord(widgetPoint.x());
    double yPixelToCoord = m_CustomPlot->yAxis->pixelToCoord(widgetPoint.y());
    handleZoomState(direction,xPixelToCoord,yPixelToCoord);
}

void CTGView::handleZoomState(CTGState::ZOOM_DIRECTION direction, double xPixelToCoord,double yPixelToCoord)
{
    CTGState::ZOOM_STATE state = CTGState::getZoomState();
    switch (state)
    {
    case CTGState::ZOOM_STATE::ZOOM_STATE0://0.5倍
    {
        if(direction==CTGState::ZOOM_DIRECTION::ZOOM_OUT)
        {
            //m_zoomState = ZOOM_STATE::ZOOM_STATE1;
            CTGState::setZoomState(CTGState::ZOOM_STATE::ZOOM_STATE1);
            m_CustomPlot->xAxis->scaleRange(2.0,xPixelToCoord);
            m_CustomPlot->yAxis->setRange(m_zoomState1YRange);
        }
        break;
    }
    case CTGState::ZOOM_STATE::ZOOM_STATE1://1.0倍
    {
        if(direction==CTGState::ZOOM_DIRECTION::ZOOM_IN)//放大
        {
            //m_zoomState = CTGState::ZOOM_STATE::ZOOM_STATE0;
            CTGState::setZoomState(CTGState::ZOOM_STATE::ZOOM_STATE0);
            m_CustomPlot->xAxis->scaleRange(0.5,xPixelToCoord);
            m_CustomPlot->yAxis->scaleRange(0.5,yPixelToCoord);
        }
        else if(direction==CTGState::ZOOM_DIRECTION::ZOOM_OUT)//缩小
        {
            CTGState::setZoomState(CTGState::ZOOM_STATE::ZOOM_STATE2);
            m_CustomPlot->xAxis->scaleRange(2.0,xPixelToCoord);
            m_CustomPlot->yAxis->setRange(m_zoomState2YRange);
        }
        break;
    }
    case CTGState::ZOOM_STATE::ZOOM_STATE2://2倍
    {
        if(direction==CTGState::ZOOM_DIRECTION::ZOOM_IN)
        {
            CTGState::setZoomState(CTGState::ZOOM_STATE::ZOOM_STATE1);
            m_CustomPlot->xAxis->scaleRange(0.5,xPixelToCoord);
            m_CustomPlot->yAxis->setRange(m_zoomState1YRange);
        }
        break;
    }
    default:
        break;
    }
}



void CTGView::timeoutHandle()
{
    //    createTestData();
    //    updatePoints();
    m_CustomPlot->replot(QCustomPlot::rpQueuedReplot);
    if((m_1cmPixUnit==-1)||(m_2cmPixUnit==-1)||(m_3cmPixUnit==-1))
    {
        QCPAxisRect * rect = m_CustomPlot->xAxis->axisRect();
        if(rect->width()>30)
        {
        initPixUnit();
        int axisWidth = rect->width();
        m_1cmRange= axisWidth/(m_1cmPixUnit)*240;
        m_2cmRange= axisWidth/(m_2cmPixUnit)*240;
        m_3cmRange= axisWidth/(m_3cmPixUnit)*240;
        handlePrinterUnitState(CTGState::PRINTER_UNIT_STATE::THREE_CM_MINUTER);
        m_CustomPlot->xAxis->setRange(-500,m_3cmRange-500);
        }
    }
}

void CTGView::createTestData()
{
    static QTime timeStart = QTime::currentTime();
    static double pi = 3.141592653589793;
    static int period = 64;
    static int A = 100;
    for(int i=0;i<100*10000;i++)
    {
        m_CustomPlot->graph(0)->addData(m_CustomPlot->graph(0)->dataCount(), A*(1+qSin(pi/2+2*pi*m_CustomPlot->graph(0)->dataCount()/period)));
    }
    //const QCPRange range = m_CustomPlot->xAxis->range();
    //m_CustomPlot->xAxis->setRange(range.lower+1,range.upper+1);
}


