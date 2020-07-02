/*
https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

Given two line segments (p1, q1) and (p2, q2), find if the given line segments intersect with each other.
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

bool IsIntersecting(Point& p1, Point& p2, Point& q1, Point& q2) 
{
    return (((q1._x - p1._x) * (p2._y - p1._y) - (q1._y - p1._y) * (p2._x - p1._x))
            * ((q2._x - p1._x) * (p2._y - p1._y) - (q2._y - p1._y) * (p2._x - p1._x)) < 0)
            &&
           (((p1._x - q1._x) * (q2._y - q1._y) - (p1._y - q1._y) * (q2._x - q1._x))
            * ((p2._x - q1._x) * (q2._y - q1._y) - (p2._y - q1._y) * (q2._x - q1._x)) < 0);
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