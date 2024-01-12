#include "CTGState.h"
CTGState::PRINTER_UNIT_STATE CTGState::m_printerUnitState = CTGState::PRINTER_UNIT_STATE::THREE_CM_MINUTER;
CTGState::FHR_GRID_SIZE_STATE CTGState::m_fhrGridSizeState = CTGState::FHR_GRID_SIZE_STATE::FHR_GRID_SIZE_STATE0;
CTGState::ZOOM_STATE CTGState::m_zoomState = CTGState::ZOOM_STATE::ZOOM_STATE1;
int CTGState::m_printerUnitPoints = (int)CTGState::PRINTER_UNIT_POINTS::PER_UNIT_POINT;
int CTGState::m_printerUnitSubTickPoints = (int)CTGState::PRINTER_UNIT_SUBTICK_POINTS::THREE_CM_SUBTICK_POINTS;//默认3厘米/分钟
int CTGState::m_printerUnitTimeTickPoints = (int)CTGState::PRINTER_UNIT_TIMETICK_POINTS::THREE_CM_TIMETICK_POINTS;
int CTGState::m_printerTimeTickSpacing = (int)CTGState::PRINTER_TIMETICK_SPACING::THREE_CM_TIMETICK_SPACING;
CTGState::PRINTER_UNIT_STATE CTGState::getPrinterUnitState()
{
    return CTGState::m_printerUnitState;
}

CTGState::FHR_GRID_SIZE_STATE CTGState::getFhrGridSizeState()
{
    return CTGState::m_fhrGridSizeState;
}

CTGState::ZOOM_STATE CTGState::getZoomState()
{
    return CTGState::m_zoomState;
}

int CTGState::getPrinterUnitPoints()
{
    return m_printerUnitPoints;
}

int CTGState::getPrinterUnitSubTickPoints()
{
    return m_printerUnitSubTickPoints;
}

int CTGState::getPrinterUnitTimeTickPoints()
{
    return m_printerUnitTimeTickPoints;
}

int CTGState::getPrinterTimeTickSpacing()
{
    return m_printerTimeTickSpacing;
}

void CTGState::setPrinterUnitState(PRINTER_UNIT_STATE state)
{
    m_printerUnitState = state;
}

void CTGState::setFhrGridSizeState(FHR_GRID_SIZE_STATE state)
{
    m_fhrGridSizeState = state;
}

void CTGState::setZoomState(ZOOM_STATE state)
{
    m_zoomState = state;
}

void CTGState::setPrinterUnitPoints(int points)
{
    m_printerUnitPoints = points;
}

void CTGState::setPrinterUnitSubTickPoints(PRINTER_UNIT_SUBTICK_POINTS points)
{
    m_printerUnitSubTickPoints = (int)points;
}

void CTGState::setPrinterUnitTimeTickPoints(PRINTER_UNIT_TIMETICK_POINTS points)
{
    m_printerUnitTimeTickPoints = (int)points;
}

void CTGState::setPrinterUnitTimeTickSpacing(PRINTER_TIMETICK_SPACING spacing)
{
    m_printerTimeTickSpacing = (int)spacing;
}
