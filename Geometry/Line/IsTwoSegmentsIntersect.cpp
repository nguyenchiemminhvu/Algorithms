/*
https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

Given two line segments (p1, q1) and (p2, q2), find if the given line segments intersect with each other.
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

int Orientation(Point a, Point b, Point c)
{
    int val = (b._y - a._y) * (c._x - b._x) - (c._y - b._y) * (b._x - a._x);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : -1;
}

bool IsIntersecting(Point& p1, Point& p2, Point& q1, Point& q2) 
{
    int o1, o2, o3, o4;
    o1 = Orientation(p1, p2, q1);
    o2 = Orientation(p1, p2, q2);
    o3 = Orientation(q1, q2, p1);
    o4 = Orientation(q1, q2, p2);

    if (o1 != o2 && o3 != o4)
        return true;

    return o1 * o2 < 0 && o3 * o4 < 0;
}

int main()
{
    Point p1 = {1, 1}, p2 = {10, 1}; 
    Point q1 = {1, 2}, q2 = {10, 2};
    if (IsIntersecting(p1, p2, q1, q2))
        std::cout << "Two segments intersect" << std::endl;
    else
        std::cout << "Two segments don't intersect" << std::endl;

    p1 = {10, 0}, p2 = {0, 10}; 
    q1 = {0, 0}, q2 = {10, 10};
    if (IsIntersecting(p1, p2, q1, q2))
        std::cout << "Two segments intersect" << std::endl;
    else
        std::cout << "Two segments don't intersect" << std::endl;

    p1 = {-5, -5}, p2 = {0, 0}; 
    q1 = {1, 1}, q2 = {10, 10};
    if (IsIntersecting(p1, p2, q1, q2))
        std::cout << "Two segments intersect" << std::endl;
    else
        std::cout << "Two segments don't intersect" << std::endl;

    return 0;
}