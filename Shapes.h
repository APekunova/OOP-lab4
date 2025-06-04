#pragma once
#include <memory>
#include <vector>
#include <string>
#include "IShape.h"

std::shared_ptr<IShape> ParseCommand(const std::string& command);
std::shared_ptr<IShape> FindShapeWithMaxArea(const std::vector<std::shared_ptr<IShape>>& shapes);
std::shared_ptr<IShape> FindShapeWithMinPerimeter(const std::vector<std::shared_ptr<IShape>>& shapes);