#pragma once
#include "CPoint.h"
#include <cmath>

inline double CalculateDistance(const CPoint& p1, const CPoint& p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}