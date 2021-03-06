/*
https://www.geeksforgeeks.org/check-line-touches-intersects-circle/

Given coordinate of the center and radius > 1 of a circle and the equation of a line. The task is to check if the given line collide with the circle or not. There are three possibilities :

Line intersect the circle.
Line touches the circle.
Line is outside the circle.

Note: General equation of a line is a*x + b*y + c = 0,
so only constant a, b, c are given in the input.

Examples :

Input : radius = 5, center = (0, 0), 
        a = 1, b = -1, c = 0.
Output : Intersect

Input :  radius = 5, center = (0, 0), 
         a = 5, b = 0, c = 0.
Output : Touch

Input : radius = 5, center = (0, 0),
         a = 1, b = 1, c = -16.
Output : Outside

The idea is to compare the perpendicular distance 
between center of circle and line with the radius of the circle.

Algorithm:
1. Find the perpendicular (say p) between center of circle and given line.
2. Compare this distance p with radius r.
……a) If p > r, then line lie outside the circle.
……b) If p = r, then line touches the circle.
……c) If p < r, then line intersect the circle.

How to find the perpendicular distance ?
https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI 3.14159265358979323846

struct Point
{
    float _x;
    float _y;

    Point(float x = 0, float y = 0)
        : _x(x), _y(y)
    {

    }

    Point(const Point &other)
    {
        _x = other._x;
        _y = other._y;
    }

    void Print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }

    double Distance(Point P)
    {
        return sqrt((P._x - _x) * (P._x - _x) + (P._y - _y) * (P._y - _y));
    }

    static int Orientation(Point a, Point b, Point c)
    {
        int val = (b._y - a._y) * (c._x - b._x) - (c._y - b._y) * (b._x - a._x);
        if (val == 0)
            return 0;
        return (val > 0) ? 1 : -1;
    }
};

struct Line
{
    float _a;
    float _b;
    float _c;

    Line(float a = 0, float b = 0, float c = 0)
        : _a(a), _b(b), _c(c)
    {

    }

    float PerpendicularDistance(Point P)
    {
        return abs(_a * P._x + _b * P._y + _c) / sqrt(_a * _a + _b * _b);
    }
};

struct Circle
{
    Point _O;
    float _r;

    Circle(Point O, float r)
        : _O(O), _r(r)
    {

    }

    float GetArea()
    {
        return (PI * _r * _r);
    }

    bool IsPointInsideCircle(Point P)
    {
        float dx = abs(_O._x - P._x);
        float dy = abs(_O._y - P._y);
        return dx * dx + dy * dy <= _r * _r;
    }

    enum RelativePosition
    {
        OUTSIDE,
        TOUCH,
        INTERSECT
    };

    RelativePosition GetRelativePosition(Line L)
    {
        float dist = L.PerpendicularDistance(_O);
        if (dist == _r)
            return RelativePosition::TOUCH;
        if (dist < _r)
            return RelativePosition::INTERSECT;
        
        return RelativePosition::OUTSIDE;
    }

    RelativePosition GetRelativePosition(Circle C)
    {
        double dist = _O.Distance(C._O);
        if (dist < _r + C._r)
            return RelativePosition::INTERSECT;
        if (dist == _r + C._r)
            return RelativePosition::TOUCH;

        return RelativePosition::OUTSIDE;
    }
};

int main()
{
    Circle C(Point(0, 0), 5);
    Line L(5, 0, 0);

    Circle::RelativePosition pos = C.GetRelativePosition(L);
    switch (pos)
    {
    case Circle::RelativePosition::INTERSECT:
        std::cout << "Intersect" << std::endl;
        break;
    case Circle::RelativePosition::TOUCH:
        std::cout << "Touch" << std::endl;
        break;
    case Circle::RelativePosition::OUTSIDE:
        std::cout << "Outside" << std::endl;
        break;
    }   
    
    return 0;
}