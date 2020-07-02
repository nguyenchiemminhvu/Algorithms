/*
https://www.geeksforgeeks.org/program-find-line-passing-2-points/

Given two points P and Q in the coordinate plane, find the equation of the line passing through both the points.

Examples:

Input : P(3, 2)
        Q(2, 6)
Output : 4x + 1y = 14

Input : P(0, 1)
        Q(2, 4)
Output : 3x + -2y = -2

Let the given two points be P(x1, y1) and Q(x2, y2). Now, we find the equation of line formed by these points.




Any line can be represented as,
ax + by = c
Let the two points satisfy the given line. So, we have,
ax1 + by1 = c
ax2 + by2 = c
We can set the following values so that all the equations hold true,

a = y2 - y1
b = x1 - x2
c = ax1 + by1
These can be derived by first getting the slope directly and then finding the intercept of the line. OR these can also be derived cleverly by a simple observation as under:

Derivation :

ax1 + by1 = c ...(i)
ax2 + by2 = c ...(ii)
Equating (i) and (ii),
ax1 + by1 = ax2 + by2
=> a(x1 - x2) = b(y2 - y1)
Thus, for equating LHS and RHS, we can simply have,
a = (y2 - y1)
AND
b = (x1 - x2)
so that we have,
(y2 - y1)(x1 - x2) = (x1 - x2)(y2 - y1)
AND
Putting these values in (i), we get,
c = ax1 + by1 
Thus, we now have the values of a, b and c which means that we have the line in the coordinate plane.
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

struct Line
{
    float _a;
    float _b;
    float _c;

    Line(float a = 0, float b = 0, float c = 0)
        : _a(a), _b(b), _c(c)
    {

    }
};

Line FindLineCutThroughTwoPoints(Point P, Point Q)
{
    Line res;
    res._a = Q._y - P._y;
    res._b = P._x - Q._x;
    res._c = res._a * P._x + res._b * P._y;

    return res;
}

int main()
{
    Point P = { 3, 2 };
    Point Q = { 2, 6 };

    Line L = FindLineCutThroughTwoPoints(P, Q);
    std::cout << L._a << "x + " << L._b << "y = " << L._c << std::endl;

    return 0;
}