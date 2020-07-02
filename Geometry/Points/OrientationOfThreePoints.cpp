/*
https://www.geeksforgeeks.org/orientation-3-ordered-points/

Orientation of an ordered triplet of points in the plane can be:
- counterclockwise
- clockwise
- colinear

If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear.
If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise and vice versa is also true.

Given three points p1, p2 and p3, find orientation of (p1, p2, p3).

Example:

Input:   p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2}
Output:  CounterClockWise

Input:   p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 1}
Output:  Colinear

The idea is to use slope.  

Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ > τ, the orientation is clockwise (right turn)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e.,  counterclockwise
*/

#include <iostream>
using namespace std;

struct Point
{
    int _x;
    int _y;

    Point(int x = 0, int y = 0)
        : _x(x), _y(y)
    {

    }
};

int Orientation(Point a, Point b, Point c)
{
    int val = (b._y - a._y) * (c._x - b._x) - (c._y - b._y) * (b._x - a._x);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : -1;
}

int main()
{
    Point a = {0, 0}, b = {4, 4}, c = {1, 2};
    
    int orientation = Orientation(a, b, c);
    if (orientation == 0)
        std::cout << "Linear" << std::endl;
    else if (orientation == 1)
        std::cout << "Clockwise" << std::endl;
    else
        std::cout << "CounterClockwise" << std::endl;

    return 0;
}