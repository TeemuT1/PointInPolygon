#include <iostream>
#include <vector>
#include "point.h"
#include "polygon.h"

// use polygon class' containsPoint method to test whether points are in a polygon
int main()
{
    // points to test against the polygon
    std::vector<Point> testPoints = {
        Point(2.0, 1.0),
        Point(-2.0, 1.0),
        Point(2.0, 2.0),
        Point(0.0, 6.0),
        Point(5.0, 1.0),
        Point(0.0, 3.0),
        Point(4.0, 4.0)

    };
    // polygon to test with
    std::vector<Point> pol = { 
        Point(0.0, 0.0),
        Point(4.0, 0.0),
        Point(3.0, 2.0),
        Point(4.0, 4.0),
        Point(2.0, 6.0),
        Point(0.0, 4.0)
    };
    Polygon polygon = Polygon(pol);
    
    //print out polygon's vertices
    std::cout << "Polygon: ";
    for (unsigned int i = 0; i < pol.size(); i++) {
        std::cout << "(" << pol[i].x << ", " << pol[i].y << ") ";
    }

    //print out whether points are in the polygon
    std::cout << "\n";
    for (unsigned int i = 0; i < testPoints.size(); i++) {
        std::cout << "Point (" << testPoints[i].x << ", " << testPoints[i].y << ") is "
            << ((polygon.containsPoint(testPoints[i]) == 1) ? "inside" : "outside") << "\n";
    }
}
