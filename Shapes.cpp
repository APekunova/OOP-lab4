#include "Shapes.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <stdexcept>
#include <algorithm>
#include <sstream>

namespace
{
    const std::string INVALID_LINE_ARGS = "Invalid line segment arguments";
    const std::string INVALID_TRIANGLE_ARGS = "Invalid triangle arguments";
    const std::string INVALID_RECTANGLE_ARGS = "Invalid rectangle arguments";
    const std::string INVALID_CIRCLE_ARGS = "Invalid circle arguments";
    const std::string UNKNOWN_SHAPE_TYPE = "Unknown shape type: ";

    uint32_t ParseColor(const std::string& colorStr)
    {
        return std::stoul(colorStr, nullptr, 16);
    }
}

std::shared_ptr<IShape> ParseCommand(const std::string& command)
{
    std::istringstream iss(command);
    std::string shapeType;
    iss >> shapeType;

    if (shapeType == "line")
    {
        double x1, y1, x2, y2;
        std::string colorStr;

        if (!(iss >> x1 >> y1 >> x2 >> y2 >> colorStr))
        {
            throw std::invalid_argument(INVALID_LINE_ARGS);
        }

        return std::make_shared<CLineSegment>(CPoint(x1, y1), CPoint(x2, y2), ParseColor(colorStr));
    }
    else if (shapeType == "triangle")
    {
        double x1, y1, x2, y2, x3, y3;
        std::string outlineColorStr, fillColorStr;

        if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> outlineColorStr >> fillColorStr))
        {
            throw std::invalid_argument(INVALID_TRIANGLE_ARGS);
        }

        return std::make_shared<CTriangle>(
            CPoint(x1, y1),
            CPoint(x2, y2),
            CPoint(x3, y3),
            ParseColor(outlineColorStr),
            ParseColor(fillColorStr)
        );
    }
    else if (shapeType == "rectangle")
    {
        double x, y, width, height;
        std::string outlineColorStr, fillColorStr;

        if (!(iss >> x >> y >> width >> height >> outlineColorStr >> fillColorStr))
        {
            throw std::invalid_argument(INVALID_RECTANGLE_ARGS);
        }

        return std::make_shared<CRectangle>(
            CPoint(x, y),
            width,
            height,
            ParseColor(outlineColorStr),
            ParseColor(fillColorStr)
        );
    }
    else if (shapeType == "circle")
    {
        double x, y, radius;
        std::string outlineColorStr, fillColorStr;

        if (!(iss >> x >> y >> radius >> outlineColorStr >> fillColorStr))
        {
            throw std::invalid_argument(INVALID_CIRCLE_ARGS);
        }

        return std::make_shared<CCircle>(
            CPoint(x, y),
            radius,
            ParseColor(outlineColorStr),
            ParseColor(fillColorStr)
        );
    }
    else
    {
        throw std::invalid_argument(UNKNOWN_SHAPE_TYPE + shapeType);
    }
}

std::shared_ptr<IShape> FindShapeWithMaxArea(const std::vector<std::shared_ptr<IShape>>& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }

    return *std::max_element(
        shapes.begin(),
        shapes.end(),
        [](const std::shared_ptr<IShape>& a, const std::shared_ptr<IShape>& b)
        {
            return a->GetArea() < b->GetArea();
        }
    );
}

std::shared_ptr<IShape> FindShapeWithMinPerimeter(const std::vector<std::shared_ptr<IShape>>& shapes)
{
    if (shapes.empty())
    {
        return nullptr;
    }

    return *std::min_element(
        shapes.begin(),
        shapes.end(),
        [](const std::shared_ptr<IShape>& a, const std::shared_ptr<IShape>& b)
        {
            return a->GetPerimeter() < b->GetPerimeter();
        }
    );
}