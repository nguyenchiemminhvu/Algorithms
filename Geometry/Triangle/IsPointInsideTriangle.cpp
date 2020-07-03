/*
https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

Given three corner points of a triangle, and one more point P. Write a function to check whether P lies within the triangle or not.
For example, consider the following program, the function should return true for P(10, 15) and false for P'(30, 15)

              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 

Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)

1) Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram. Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
2) Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1.
3) Calculate area of the triangle PBC. Let this area be A2.
4) Calculate area of the triangle PAC. Let this area be A3.
5) If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.
*/

#include <iostream>
#include <cmath>
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

struct Triangle
{
    Point _A;
    Point _B;
    Point _C;

    Triangle(Point A, Point B, Point C)
        : _A(A), _B(B), _C(C)
    {

    }

    double GetArea()
    {
        double a = sqrt((_B._x - _A._x) * (_B._x - _A._x) + (_B._y - _A._y) * (_B._y - _A._y));
        double b = sqrt((_C._x - _B._x) * (_C._x - _B._x) + (_C._y - _B._y) * (_C._y - _B._y));
        double c = sqrt((_C._x - _A._x) * (_C._x - _A._x) + (_C._y - _A._y) * (_C._y - _A._y));
        double s = (a + b + c) / 2;

        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

bool IsPointInsideTriangle(Triangle T, Point P)
{
    Triangle T1(T._A, T._B, P);
    Triangle T2(T._B, T._C, P);
    Triangle T3(T._A, T._C, P);
    
    return (float)T.GetArea() == ((float)T1.GetArea() + (float)T2.GetArea() + (float)T3.GetArea());
}

int main()
{
    Point A(0, 0);
    Point B(10, 30);
    Point C(20, 0);

    Triangle T(A, B, C);

    Point P1(10, 15);
    Point P2(30, 15);

    if (IsPointInsideTriangle(T, P1))
        std::cout << "P1(" << P1._x << ", " << P1._y << ") is inside the triangle" << std::endl;
    else
        std::cout << "P1(" << P1._x << ", " << P1._y << ") is not inside the triangle" << std::endl;

    if (IsPointInsideTriangle(T, P2))
        std::cout << "P2(" << P2._x << ", " << P2._y << ") is inside the triangle" << std::endl;
    else
        std::cout << "P2(" << P2._x << ", " << P2._y << ") is not inside the triangle" << std::endl;
    
    return 0;
}