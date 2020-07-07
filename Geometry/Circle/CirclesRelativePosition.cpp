/*
https://www.geeksforgeeks.org/check-two-given-circles-touch-intersect/


*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-6
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
    Circle C1(Point(-10, 8), 30);
    Circle C2(Point(14, -24), 10);

    Circle::RelativePosition pos = C1.GetRelativePosition(C2);
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