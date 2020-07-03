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

    

    return 0;
}