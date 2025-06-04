#pragma once
#include <string>
#include <iomanip>
#include <sstream>

inline std::string ColorToString(uint32_t color)
{
    std::stringstream ss;
    ss << "#" << std::hex << std::setw(6) << std::setfill('0') << color;
    return ss.str();
}