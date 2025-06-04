#include "ShapeProcessor.h"
#include "Shapes.h"
#include <iostream>

namespace
{
    const std::string INPUT_PROMPT = "Enter shapes (line, triangle, rectangle, circle) or Ctrl+Z to finish:\n";
    const std::string ERROR_PREFIX = "Error: ";
    const std::string MAX_AREA_TITLE = "Shape with maximum area:";
    const std::string MIN_PERIMETER_TITLE = "Shape with minimum perimeter:";
    const std::string NO_SHAPES_MSG = "No shapes found";
    const std::string NEWLINE = "\n";
}

void ShapeProcessor::ProcessShapes()
{
    ReadShapesFromInput();

    auto maxAreaShape = FindShapeWithMaxArea(shapes);
    auto minPerimeterShape = FindShapeWithMinPerimeter(shapes);

    PrintShapeInfo(maxAreaShape, MAX_AREA_TITLE);
    PrintShapeInfo(minPerimeterShape, MIN_PERIMETER_TITLE);
}

void ShapeProcessor::ReadShapesFromInput()
{
    std::string line;
    std::cout << INPUT_PROMPT;

    while (std::getline(std::cin, line))
    {
        try
        {
            auto shape = ParseCommand(line);
            shapes.push_back(shape);
        }
        catch (const std::exception& e)
        {
            std::cerr << ERROR_PREFIX << e.what() << std::endl;
        }
    }
}

void ShapeProcessor::PrintShapeInfo(const std::shared_ptr<IShape>& shape, const std::string& title) const
{
    std::cout << NEWLINE << title << NEWLINE;

    if (shape)
    {
        std::cout << shape->ToString() << std::endl;
    }
    else
    {
        std::cout << NO_SHAPES_MSG << std::endl;
    }
}