/*
https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/

Given a set of points as and a line as ax+by+c = 0.
We need to find a point on given line for which sum of distances from given set of points is minimum.

If we take one point on given line at infinite distance then total distance cost will be infinite, 
now when we move this point on line towards given points the total distance cost starts decreasing and after some time, 
it again starts increasing which reached to infinite on the other infinite end of line so distance cost curve looks like a U-curve 
and we have to find the bottom value of this U-curve.

As U-curve is not monotonically increasing or decreasing we can’t use binary search for finding bottom most point, 
here we will use ternary search for finding bottom most point, 
ternary search skips one third of search space at each iteration, 
you can read more about ternary search here.

So solution proceeds as follows:

We start with low and high initialized as some smallest and largest values respectively, 
then we start iteration, in each iteration we calculate two mids, mid1 and mid2, which represent 1/3rd and 2/3rd position in search space, 
we calculate total distance of all points with mid1 and mid2 and update low or high by comparing these distance cost, 
this iteration continues untill low and high become approximately equal.
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

    float PerpendicularDistance(Point P)
    {
        return abs(_a * P._x + _b * P._y + _c) / sqrt(_a * _a + _b * _b);
    }

    float MinimumDistanceToAllPoints(std::vector<Point> points, Point &closetPoint)
    {
        auto Compute = [=](std::vector<Point> points, double X, Point &closet) -> double
        {
            double res = 0;
            double Y = -1 * (_c + _a * X) / _b;
            for (int i = 0; i < points.size(); i++)
                res += points[i].Distance(Point(X, Y));

            closet = Point(X, Y);
            return res;
        };

        double low = -1e6;
        double high = 1e6;

        while ((high - low) > EPS)
        {
            double mid1 = low + (high - low) / 3;
            double mid2 = high - (high - low) / 3;

            double Dist1 = Compute(points, mid1, closetPoint);
            double Dist2 = Compute(points, mid2, closetPoint);

            if (Dist1 < Dist2)
                high = mid2;
            else
                low = mid1;
        }
        
        return Compute(points, (low + high) / 2, closetPoint);
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

int main()
{
    Line L(1, -1, -3);
    std::vector<Point> points = { {-3, -2}, {-1, 0}, {-1, 2}, {1, 2}, {3, 4} };
    Point closetPoint;

    std::cout << L.MinimumDistanceToAllPoints(points, closetPoint) << std::endl;
    closetPoint.Print();

    return 0;
}