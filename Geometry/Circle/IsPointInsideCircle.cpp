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

    bool IsPointInsideCircle(Point P)
    {
        float dx = abs(_O._x - P._x);
        float dy = abs(_O._y - P._y);
        return dx * dx + dy * dy <= _r * _r;
    }
};

int main()
{
    Circle C(Point(1, 1), 5);
    Point P(1, 5);

    if (C.IsPointInsideCircle(P))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    return 0;
}