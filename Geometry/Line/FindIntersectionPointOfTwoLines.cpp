/*
https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/

Given points A and B corresponding to line AB and points P and Q corresponding to line PQ, find the point of intersection of these lines. The points are given in 2D Plane with their X and Y Coordinates.

Examples:

Input : A = (1, 1), B = (4, 4)
        C = (1, 8), D = (2, 4)
Output : The intersection of the given lines 
         AB and CD is: (2.4, 2.4)

Input : A = (0, 1), B = (0, 4)
        C = (1, 8), D = (1, 4)
Output : The given lines AB and CD are parallel.

First of all, let us assume that we have two points (x1, y1) and (x2, y2). Now, we find the equation of line formed by these points.

Let the given lines be :

a1x + b1y = c1
a2x + b2y = c2

We have to now solve these 2 equations to find the point of intersection. To solve, we multiply 1. by b2 and 2 by b1
This gives us:

a1b2x + b1b2y = c1b2
a2b1x + b2b1y = c2b1

Subtracting these we get,
(a1b2 – a2b1) x = c1b2 – c2b1
(b1a2 - a1b2) y = c1a2 - a1c2

This gives us the value of x. Similarly, we can find the value of y. (x, y) gives us the point of intersection.
*/

#include <iostream>
using namespace std;

struct Point
{
    float _x;
    float _y;

    Point(float x = 0, float y = 0)
        : _x(x), _y(y)
    {

    }

    void Print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
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
};

int main()
{
    Point A(1, 1); 
    Point B(4, 4); 
    Point C(1, 8); 
    Point D(2, 4);

    Line L1(A, B);
    Line L2(C, D);

    Point I;
    if (L1.FindIntersectingPoint(L2, I))
    {
        I.Print();
    }
    else
    {
        std::cout << "The lines are parallel, no intersecting point" << std::endl;
    }

    return 0;
}