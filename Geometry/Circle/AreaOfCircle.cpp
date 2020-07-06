/*
https://www.geeksforgeeks.org/c-program-find-area-circle/

Area = pi * r2
where r is radius of circle 
*/

#include <iostream>
#include <cmath>
#include <algorithm>
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

    void Print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }
};

struct Circle
{
    Point _O;
    float _r;

    Circle(Point O, float r)
        : _O(O), _r(r)
    {

    }

    float GetArea()
    {
        return (PI * _r * _r);
    }
};

int main()
{
    Circle c(Point(0, 0), 5);
    std::cout << c.GetArea() << std::endl;
    
    return 0;
}