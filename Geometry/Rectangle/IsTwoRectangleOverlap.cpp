/*
https://www.geeksforgeeks.org/find-two-rectangles-overlap/

Given two rectangles, find if the given two rectangles overlap or not.
Note that a rectangle can be represented by two coordinates, top left and bottom right. So mainly we are given following four coordinates.
l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

We need to write a function bool doOverlap(l1, r1, l2, r2) that returns true if the two given rectangles overlap.

Two rectangles do not overlap if one of the following conditions is true.
1) One rectangle is above top edge of other rectangle.
2) One rectangle is on left side of left edge of other rectangle.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
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

struct Rectangle
{
    Point _anchor;
    float _width;
    float _height;

    Rectangle(Point anchor, float width = 0, float height = 0)
        : _anchor(anchor), _width(width), _height(height)
    {

    }

    bool IsOverlap(const Rectangle &other)
    {
        if (_anchor._x + _width < other._anchor._x || _anchor._x > other._anchor._x + other._width)
            return false;
        
        if (_anchor._y + _height < other._anchor._y || _anchor._y > other._anchor._y + other._height)
            return false;
        
        return true;
    }
};

int main()
{
    Rectangle R1(Point(0, 0), 10, 10);
    Rectangle R2(Point(5, 0), 10, 5);

    if (R1.IsOverlap(R2))
    {
        std::cout << "Overlap" << std::endl;
    }
    else
    {
        std::cout << "Not overlap" << std::endl;
    }
    
    return 0;
}