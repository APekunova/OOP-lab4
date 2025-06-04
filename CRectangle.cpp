#include "CRectangle.h"
#include <sstream>
#include <iomanip>
#include "ColorUtils.h"

namespace
{
    const std::string RECTANGLE_HEADER = "Rectangle:\n";
    const std::string LEFT_TOP_PREFIX = "  Left Top: (";
    const std::string WIDTH_PREFIX = "  Width: ";
    const std::string HEIGHT_PREFIX = "  Height: ";
    const std::string RIGHT_BOTTOM_PREFIX = "  Right Bottom: (";
    const std::string OUTLINE_COLOR_PREFIX = "  Outline Color: ";
    const std::string FILL_COLOR_PREFIX = "  Fill Color: ";
    const std::string AREA_PREFIX = "  Area: ";
    const std::string PERIMETER_PREFIX = "  Perimeter: ";
    const std::string COORDINATE_SEPARATOR = ", ";
    const std::string COORDINATE_SUFFIX = ")";
    const std::string NEW_LINE = "\n";
}

CRectangle::CRectangle(const CPoint& leftTop, double width, double height,
    uint32_t outlineColor, uint32_t fillColor)
    : m_leftTop(leftTop), m_width(width), m_height(height),
    m_outlineColor(outlineColor), m_fillColor(fillColor) {}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
    std::stringstream ss;
    ss << RECTANGLE_HEADER
        << LEFT_TOP_PREFIX << m_leftTop.x << COORDINATE_SEPARATOR << m_leftTop.y << COORDINATE_SUFFIX << NEW_LINE
        << WIDTH_PREFIX << m_width << NEW_LINE
        << HEIGHT_PREFIX << m_height << NEW_LINE
        << RIGHT_BOTTOM_PREFIX << (m_leftTop.x + m_width) << COORDINATE_SEPARATOR
        << (m_leftTop.y + m_height) << COORDINATE_SUFFIX << NEW_LINE
        << OUTLINE_COLOR_PREFIX << ColorToString(m_outlineColor) << NEW_LINE
        << FILL_COLOR_PREFIX << ColorToString(m_fillColor) << NEW_LINE
        << AREA_PREFIX << GetArea() << NEW_LINE
        << PERIMETER_PREFIX << GetPerimeter();
    return ss.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
    return CPoint(m_leftTop.x + m_width, m_leftTop.y + m_height);
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}