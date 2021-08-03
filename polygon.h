#pragma once
#include <vector>
#include "point.h"
class Polygon
{
public:
	Polygon();
	Polygon(std::vector<Point> points);

	bool containsPoint(Point point);

	std::vector<Point> vertices;
};