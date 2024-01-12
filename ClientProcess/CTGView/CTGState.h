#ifndef CTGSTATE_H
#define CTGSTATE_H
class CTGState
{
public:
    enum PRINTER_UNIT_STATE //走纸速度单位状态
    {
        ONE_CM_MINUTER=0,  //1cm/min
        TWO_CM_MINUTER=1,  //2cm/min
        THREE_CM_MINUTER=2 //3cm/min
    };
    enum FHR_GRID_SIZE_STATE //胎心y轴范围
    {
        FHR_GRID_SIZE_STATE0, //胎心Y轴范围为30-210
        FHR_GRID_SIZE_STATE1  //胎心Y轴范围为50-240
    };
    enum ZOOM_STATE   //坐标系缩放范围,以放大为基准
    {
        ZOOM_STATE0, //0.5倍
        ZOOM_STATE1, //1.0倍，正常范围
        ZOOM_STATE2, //2倍
    };
    enum ZOOM_DIRECTION//缩放方向
    {
        ZOON_NORMAL,//正常状态下
        ZOOM_IN,//放大
        ZOOM_OUT//缩小
    };
    enum PRINTER_UNIT_TIMETICK_POINTS
    {
        ONE_CM_TIMETICK_POINTS =  2400, //1cm 10min点数
        TWO_CM_TIMETICK_POINTS =  1200, //2cm 5min点数
        THREE_CM_TIMETICK_POINTS = 1200, //3cm 5min点数
    };
    enum PRINTER_TIMETICK_SPACING
    {
        ONE_CM_TIMETICK_SPACING  =  10, //10min
        TWO_CM_TIMETICK_SPACING  =  5, //5min
        THREE_CM_TIMETICK_SPACING = 5, //5min
    };
    enum PRINTER_UNIT_SUBTICK_POINTS
    {
        ONE_CM_SUBTICK_POINTS = 120,
        TWO_CM_SUBTICK_POINTS = 120,
        THREE_CM_SUBTICK_POINTS = 80,
    };
    enum PRINTER_UNIT_POINTS
    {
        PER_UNIT_POINT = 240 //每1分钟打印240个点
    };
protected:
    static PRINTER_UNIT_STATE m_printerUnitState;
    static FHR_GRID_SIZE_STATE m_fhrGridSizeState;
    static ZOOM_STATE m_zoomState;
    static int m_printerUnitSubTickPoints;//默认3厘米/分钟
    static int m_printerUnitPoints;//每1分钟打印240个点
    static int m_printerUnitTimeTickPoints;
    static int m_printerTimeTickSpacing;
public:
    static PRINTER_UNIT_STATE getPrinterUnitState();
    static FHR_GRID_SIZE_STATE getFhrGridSizeState();
    static ZOOM_STATE getZoomState();
    static int getPrinterUnitPoints();
    static int getPrinterUnitSubTickPoints();
    static int getPrinterUnitTimeTickPoints();
    static int getPrinterTimeTickSpacing();
public:
    static void setPrinterUnitState(PRINTER_UNIT_STATE state);
    static void setFhrGridSizeState(FHR_GRID_SIZE_STATE state);
    static void setZoomState(ZOOM_STATE state);
    static void setPrinterUnitPoints(int points);
    static void setPrinterUnitSubTickPoints(PRINTER_UNIT_SUBTICK_POINTS points);
    static void setPrinterUnitTimeTickPoints(PRINTER_UNIT_TIMETICK_POINTS points);
    static void setPrinterUnitTimeTickSpacing(PRINTER_TIMETICK_SPACING spacing);
};
#endif // CSTATE_H
