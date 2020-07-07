/*
https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/

Given a polygon and a point ‘p’, find if ‘p’ lies inside the polygon or not.
The points lying on the border are considered inside.

1) Draw a horizontal line to the right of each point and extend it to infinity

1) Count the number of times the line intersects with polygon edges.

2) A point is inside the polygon if either count of intersections is odd or
   point lies on an edge of polygon.  If none of the conditions is true, then 
   point lies outside.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
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

    Line(Point A, Point B)
    {
        this->_a = B._y - A._y;
        this->_b = A._x - B._x;
        this->_c = this->_a * A._x + this->_b * A._y;
    }

    bool FindIntersectingPoint(Line L, Point &I)
    {
        float determinant = _a * L._a - _b * L._b;
        if (determinant == 0) // parallel case
        {
            return false;
        }

        I._x = (_c * L._b - L._c * _b) / (_a * L._b - L._a * _b);
        I._y = (_c * L._a - _a * L._c) / (_b * L._a - _a * L._b);
        return true;
    }

    void Print()
    {
        std::cout << _a << "x + " << _b << "y = " << _c << std::endl;
    }

    static bool IsIntersecting(Point p1, Point p2, Point q1, Point q2) 
    {
        int o1, o2, o3, o4;
        o1 = Point::Orientation(p1, p2, q1);
        o2 = Point::Orientation(p1, p2, q2);
        o3 = Point::Orientation(q1, q2, p1);
        o4 = Point::Orientation(q1, q2, p2);

        if (o1 != o2 && o3 != o4)
            return true;

        return o1 * o2 < 0 && o3 * o4 < 0;
    }

    static bool OnSegment(Point A, Point B, Point O)
    {
        if (O._x <= std::max(A._x, B._x) && O._x >= std::min(A._x, B._x)
        &&  O._y <= std::max(A._y, B._y) && O._y >= std::min(A._y, B._y))
            return true;
        
        return false;
    }
};

struct Polygon
{
    std::vector<Point> _pol;

    Polygon(std::vector<Point> pol)
        : _pol(pol)
    {

    }

    bool IsPointInside(Point P)
    {
        if (_pol.size() < 3)
            return false;
        
        Point extreme(INT16_MAX, P._y);

        int count = 0, i = 0;
        do
        {
            int next = (i + 1) % _pol.size();
            Point A(_pol[i]);
            Point B(_pol[next]);

            if (Line::IsIntersecting(A, B, P, extreme))
            {
                if (Point::Orientation(A, P, B) == 0)
                {
                    return Line::OnSegment(A, B, P);
                }

                count++;
            }

            i = next;

        } while (i != 0);
        
        return count & 1;
    }

    void Print()
    {
        for (Point p : _pol)
        {
            p.Print();
        }
        std::cout << endl;
    }
};

int main()
{
    Polygon polygon1({ {0, 0}, {10, 0}, {10, 10}, {0, 10} });
    Point P1(20, 20);
    if (polygon1.IsPointInside(P1))
        std::cout << "P1 is inside polygon1" << std::endl;

    Polygon polygon2({ {0, 0}, {5, 5}, {5, 0} });
    Point P2(3, 3);
    if (polygon2.IsPointInside(P2))
        std::cout << "P2 is inside polygon2" << std::endl;

    Polygon polygon3({ {0, 0}, {10, 0}, {10, 10}, {0, 10} });
    Point P3(0, 10);
    if (polygon3.IsPointInside(P3))
        std::cout << "P3 is inside polygon3" << std::endl;

    return 0;
}