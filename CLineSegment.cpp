#include "CLineSegment.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include "ColorUtils.h"
#include "GeometryUtils.h"

namespace
{
    const std::string LINE_SEGMENT_HEADER = "Line Segment:\n";
    const std::string START_POINT_PREFIX = "  Start Point: (";
    const std::string END_POINT_PREFIX = "  End Point: (";
    const std::string OUTLINE_COLOR_PREFIX = "  Outline Color: ";
    const std::string LENGTH_PREFIX = "  Length: ";
    const std::string COORDINATE_SEPARATOR = ", ";
    const std::string COORDINATE_SUFFIX = ")";
}

CLineSegment::CLineSegment(const CPoint& start, const CPoint& end, uint32_t outlineColor)
    : m_startPoint(start), m_endPoint(end), m_outlineColor(outlineColor) {}

double CLineSegment::GetArea() const
{
    return 0.0;
}

double CLineSegment::GetPerimeter() const
{
    return CalculateDistance(m_startPoint, m_endPoint);
}

std::string CLineSegment::ToString() const
{
    std::stringstream ss;
    ss << LINE_SEGMENT_HEADER
        << START_POINT_PREFIX << m_startPoint.x << COORDINATE_SEPARATOR << m_startPoint.y << COORDINATE_SUFFIX << "\n"
        << END_POINT_PREFIX << m_endPoint.x << COORDINATE_SEPARATOR << m_endPoint.y << COORDINATE_SUFFIX << "\n"
        << OUTLINE_COLOR_PREFIX << ColorToString(m_outlineColor) << "\n"
        << LENGTH_PREFIX << GetPerimeter();
    return ss.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}