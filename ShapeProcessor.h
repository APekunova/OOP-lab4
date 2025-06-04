#pragma once
#include <vector>
#include <memory>
#include "IShape.h"

class ShapeProcessor
{
public:
    void ProcessShapes();

private:
    std::vector<std::shared_ptr<IShape>> shapes;

    void ReadShapesFromInput();
    void PrintShapeInfo(const std::shared_ptr<IShape>& shape, const std::string& title) const;
};