/*
https://www.geeksforgeeks.org/program-check-three-points-collinear/

Given three points, check whether they lie on a straight (collinear) or not

Examples :

Input : (1, 1), (1, 4), (1, 5)
Output : Yes 
The points lie on a straight line

Input : (1, 5), (2, 5), (4, 6)
Output : No 
The points do not lie on a straight line
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

    bool IsPointOnTheLine(Point P)
    {
        return _a * P._x + _b * P._y == _c;
    }

    void Print()
    {
        std::cout << _a << "x + " << _b << "y = " << _c << std::endl;
    }
};

int main()
{
    Point A(1, 1);
    Point B(1, 4);
    Point C(1, 5);

    Line L(A, B);
    if (L.IsPointOnTheLine(C))
    {
        std::cout << "Colinear" << std::endl;
    }
    else
    {
        std::cout << "Not colinear" << std::endl;
    }
    
    return 0;
}