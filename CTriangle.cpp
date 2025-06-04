#include "CTriangle.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include "GeometryUtils.h"
#include "ColorUtils.h"

namespace
{
    const std::string TRIANGLE_HEADER = "Triangle:\n";
    const std::string VERTEX_PREFIX = "  Vertex";
    const std::string OUTLINE_COLOR_PREFIX = "  Outline Color: ";
    const std::string FILL_COLOR_PREFIX = "  Fill Color: ";
    const std::string AREA_PREFIX = "  Area: ";
    const std::string PERIMETER_PREFIX = "  Perimeter: ";
    const std::string COORDINATE_SEPARATOR = ", ";
    const std::string COORDINATE_SUFFIX = ")";
    const std::string NEW_LINE = "\n";
}

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3,
    uint32_t outlineColor, uint32_t fillColor)
    : m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3),
    m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

double CTriangle::GetArea() const
{
    return abs((m_vertex1.x * (m_vertex2.y - m_vertex3.y) +
        m_vertex2.x * (m_vertex3.y - m_vertex1.y) +
        m_vertex3.x * (m_vertex1.y - m_vertex2.y)) / 2.0);
}

double CTriangle::GetPerimeter() const
{
    return CalculateDistance(m_vertex1, m_vertex2) +
        CalculateDistance(m_vertex2, m_vertex3) +
        CalculateDistance(m_vertex3, m_vertex1);
}

std::string CTriangle::ToString() const
{
    std::stringstream ss;
    ss << TRIANGLE_HEADER
        << VERTEX_PREFIX << "1: (" << m_vertex1.x << COORDINATE_SEPARATOR << m_vertex1.y << COORDINATE_SUFFIX << NEW_LINE
        << VERTEX_PREFIX << "2: (" << m_vertex2.x << COORDINATE_SEPARATOR << m_vertex2.y << COORDINATE_SUFFIX << NEW_LINE
        << VERTEX_PREFIX << "3: (" << m_vertex3.x << COORDINATE_SEPARATOR << m_vertex3.y << COORDINATE_SUFFIX << NEW_LINE
        << OUTLINE_COLOR_PREFIX << ColorToString(m_outlineColor) << NEW_LINE
        << FILL_COLOR_PREFIX << ColorToString(m_fillColor) << NEW_LINE
        << AREA_PREFIX << GetArea() << NEW_LINE
        << PERIMETER_PREFIX << GetPerimeter();
    return ss.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
    return m_vertex3;
}