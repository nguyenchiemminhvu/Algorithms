/*
https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/

Given a set of points in the plane.
The convex hull of the set is the smallest convex polygon that contains all the points of it.

The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) and we keep wrapping points in counterclockwise direction. The big question is, given a point p as current point, how to find the next point in output? The idea is to use orientation() here. Next point is selected as the point that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, we have “orientation(p, q, r) = counterclockwise”. Following is the detailed algorithm.

1) Initialize p as leftmost point.
2) Do following while we don’t come back to the first (or leftmost) point.
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r.
…..b) next[p] = q (Store q as next of p in the output convex hull).
…..c) p = q (Set p as q for next iteration).

Time Complexity:
For every point on the hull we examine all the other points to determine the next point.
Time complexity is (m * n) where n is number of input points and m is number of output or hull points (m <= n).
In worst case, time complexity is O(n 2).
The worst case occurs when all the points are on the hull (m = n)
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

    void GetConvexHull(std::vector<Point> &hull)
    {
        hull.clear();

        if (_pol.size() < 3)
            return;

        // Find leftmost point
        int left = 0;
        for (int i = 1; i < _pol.size(); i++)
        {
            if (_pol[i]._x < _pol[left]._x)
            {
                left = i;
            }
        }


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
    Polygon pol( { {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3} } );

    std::vector<Point> hull;
    pol.GetConvexHull(hull);

    if (hull.empty())
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        for (Point p : hull)
        {
            p.Print();
        }   
    }

    return 0;
}