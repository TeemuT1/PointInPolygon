#include "point.h"
#include "polygon.h"
#include <iostream>

Polygon::Polygon() : vertices() {}
Polygon::Polygon(std::vector<Point> points) {
	vertices = points;
}

/*	Uses ray casting to determine whether a point is inside the polygon.
	If a ray cast from the point directly to the right until infinity intersects with the polygon's
	sides an odd number of times, the point is inside, otherwise outside
*/
bool Polygon::containsPoint(Point point) {

	// counter to keep track of the number of intersects
	int intersects = 0;

	// loop through all vertice pairs defining the sides of the polygon
	for (unsigned int i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
		float p1x = vertices[i].x;
		float p1y = vertices[i].y;
		float p2x = vertices[j].x;
		float p2y = vertices[j].y;

		// If the point is to the right or on top of both vertices, cannot intersect
		if (p1x <= point.x && p2x <= point.x) {
			continue;
		}

		/*	One vertex should be higher, one lower than the point for an intersection to be possible
		 
			Considering edge cases:
			If the y coordinate of the point is the same as vertex with the higher y coordinate,
			an intersection is possible. If same with the lower, not possible.
		*/
		if ((p1y >= point.y && p2y < point.y) || (p2y >= point.y && p1y < point.y)) {
			// If both vertices x coordinates are higher than the point's, there will be intersection.
			if (p1x > point.x && p2x > point.x) {
				intersects++;
				continue;
			}

			/*  One vertex is to the left, one to the right of the point.
				Calculate the line going through the vertices and determine if the 
				x coordinate of the line is higher than the point's x at the point's y coordinate,
				there will be intersection.
				Cannot end up here if p1y == p2y so no division with 0.
			*/
			float slopeOfLine = (p1x - p2x) / (p1y - p2y);
			float xOfLineConnectingVertices = slopeOfLine * (point.y - p1y) + p1x;
			if (xOfLineConnectingVertices > point.x) {
				intersects++;
			}
		}
	}
	// Return true (point inside) if odd intersections, false (point outside) if even.
	return (intersects % 2 == 1);
}