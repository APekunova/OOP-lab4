#define CATCH_CONFIG_MAIN
#include "Shapes.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include <iostream>
#include "../catch2/catch.hpp"

TEST_CASE("Point basic functionality")
{
    std::cout << "\n=== Testing Point basic functionality ===\n";
    CPoint p1(1.5, 2.5);

    std::cout << "Checking X coordinate storage";
    REQUIRE(p1.x == Approx(1.5));
    std::cout << " PASSED\n";

    std::cout << "Checking Y coordinate storage";
    REQUIRE(p1.y == Approx(2.5));
    std::cout << " PASSED\n";
}

TEST_CASE("Line Segment operations")
{
    std::cout << "\n=== Testing Line Segment operations ===\n";
    CLineSegment line(CPoint(1.0, 1.0), CPoint(4.0, 5.0), 0xFF0000);

    std::cout << "Checking start point";
    REQUIRE(line.GetStartPoint().x == Approx(1.0));
    REQUIRE(line.GetStartPoint().y == Approx(1.0));
    std::cout << " PASSED\n";

    std::cout << "Checking length calculation";
    REQUIRE(line.GetPerimeter() == Approx(5.0));
    std::cout << " PASSED\n";

    std::cout << "Checking area (should be 0)";
    REQUIRE(line.GetArea() == Approx(0.0));
    std::cout << " PASSED\n";
}

TEST_CASE("Triangle validation") {
    std::cout << "\n=== Testing Triangle validation ===\n";
    CTriangle triangle(
        CPoint(0.0, 0.0),
        CPoint(3.0, 0.0),
        CPoint(0.0, 4.0),
        0x00FF00,
        0x0000FF
    );

    std::cout << "Checking vertices storage";
    REQUIRE(triangle.GetVertex1().x == Approx(0.0));
    REQUIRE(triangle.GetVertex3().y == Approx(4.0));
    std::cout << " PASSED\n";

    std::cout << "Checking area calculation";
    REQUIRE(triangle.GetArea() == Approx(6.0));
    std::cout << " PASSED\n";

    std::cout << "Checking perimeter calculation";
    REQUIRE(triangle.GetPerimeter() == Approx(12.0));
    std::cout << " PASSED\n";
}

TEST_CASE("Shape parser")
{
    std::cout << "\n=== Testing Shape parser ===\n";

    std::cout << "Testing line segment parsing";
    auto line = ParseCommand("line 1 2 3 4 ff0000");
    REQUIRE(line->GetPerimeter() == Approx(2.828427));
    std::cout << " PASSED\n";

    std::cout << "Testing triangle parsing";
    auto triangle = ParseCommand("triangle 0 0 3 0 0 4 00ff00 0000ff");
    REQUIRE(triangle->GetArea() == Approx(6.0));
    std::cout << " PASSED\n";

    std::cout << "Testing invalid command handling";
    REQUIRE_THROWS_AS(ParseCommand("invalid_command"), std::invalid_argument);
    std::cout << " PASSED\n";
}

TEST_CASE("Shape analysis functions")
{
    std::cout << "\n=== Testing Shape analysis ===\n";
    std::vector<std::shared_ptr<IShape>> shapes;

    std::cout << "Adding test shapes";
    shapes.push_back(ParseCommand("line 0 0 3 4 000000"));
    shapes.push_back(ParseCommand("rectangle 0 0 2 3 000000 000000"));
    shapes.push_back(ParseCommand("circle 0 0 2 000000 000000"));
    std::cout << " DONE\n";

    std::cout << "Testing FindShapeWithMaxArea";
    auto maxArea = FindShapeWithMaxArea(shapes);
    REQUIRE(maxArea->GetArea() == Approx(12.5663706144));
    std::cout << " PASSED\n";

    std::cout << "Testing FindShapeWithMinPerimeter";
    auto minPerimeter = FindShapeWithMinPerimeter(shapes);
    REQUIRE(minPerimeter->GetPerimeter() == Approx(5.0));
    std::cout << " PASSED\n";
}

int main(int argc, char* argv[]) {
    std::cout << "===== Starting Geometry Tests =====\n";
    int result = Catch::Session().run(argc, argv);
    std::cout << "===== Tests completed: " << (result ? "FAILED" : "PASSED") << " =====\n";
    return result;
}