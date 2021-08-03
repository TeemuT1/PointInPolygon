# Point in polygon
An algorithm to determine whether a point is inside a polygon written in C++.

The main program creates a polygon and tests the algorithm with some points. The algorithm is in the polygon class' containsPoint method.

The algorithm uses the ray casting method. If a line is drawn starting from the point towards infinity to the right, count how many times it would intersect with the polygon's sides. If it intersects an odd number of times, it is inside the polygon, if even, outside.

Edge cases:
1. Point has the same x-coordinate as a vertical line: will not intersect
2. Point has the same y-coordinate as a horizontal line: will not intersect
3. Point has the same y-coordinate (and smaller x) as one of the side's vertices : if the other vertex is lower, will intersect, if higher, will not.

Adding support for inner loops: The method could be called for each of the polygons making up the area. If the number of polygons containing the point is odd, it is inside, if even, outside.

If there are many polygons and the test needs to be done often, might be good to save polygon's bounding box (rectangle containing the polygon) and test against it as an initial test.

Currently the algorithm is in the polygon class, maybe should be a library function instead.