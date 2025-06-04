#include "CCircle.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include "ColorUtils.h"

namespace
{
    const std::string CIRCLE_HEADER = "Circle:\n";
    const std::string CENTER_PREFIX = "  Center: (";
    const std::string RADIUS_PREFIX = "  Radius: ";
    const std::string OUTLINE_COLOR_PREFIX = "  Outline Color: ";
    const std::string FILL_COLOR_PREFIX = "  Fill Color: ";
    const std::string AREA_PREFIX = "  Area: ";
    const std::string PERIMETER_PREFIX = "  Perimeter: ";
    const std::string COORDINATE_SEPARATOR = ", ";
    const std::string COORDINATE_SUFFIX = ")";
    const std::string NEW_LINE = "\n";
}

const double PI = 3.14159265358979323846;

CCircle::CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor)
    : m_center(center), m_radius(radius),
    m_outlineColor(outlineColor), m_fillColor(fillColor) {}

double CCircle::GetArea() const
{
    return PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
    return 2 * PI * m_radius;
}

std::string CCircle::ToString() const
{
    std::stringstream ss;
    ss << CIRCLE_HEADER
        << CENTER_PREFIX << m_center.x << COORDINATE_SEPARATOR << m_center.y << COORDINATE_SUFFIX << NEW_LINE
        << RADIUS_PREFIX << m_radius << NEW_LINE
        << OUTLINE_COLOR_PREFIX << ColorToString(m_outlineColor) << NEW_LINE
        << FILL_COLOR_PREFIX << ColorToString(m_fillColor) << NEW_LINE
        << AREA_PREFIX << GetArea() << NEW_LINE
        << PERIMETER_PREFIX << GetPerimeter();
    return ss.str();
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}