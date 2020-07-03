/*
https://www.geeksforgeeks.org/find-angles-given-triangle/

Given coordinates of all three vertices of the triangle in the 2D plane, the task is to find all three angles.

Example:

Input : A = (0, 0), 
        B = (0, 1), 
        C = (1, 0)
Output : 90, 45, 45

To solve this problem we use below Law of cosines.
https://en.wikipedia.org/wiki/Law_of_cosines

c^2 = a^2 + b^2 - 2(a)(b)(cos beta)
=>
beta = acos( ( a^2 + b^2 - c^2 ) / (2ab) )

First, calculate the length of all the sides. 
Then apply above formula to get all angles in 
radian. Then convert angles from radian into 
degrees.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI 3.1415926535

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
    enum SideType
    {
        SCALENE,
        ISOSCELES,
        EQUILATERAL
    };

    enum AngleType
    {
        ACUTE,
        RIGHT,
        OBTUSE
    };

    Point _A;
    Point _B;
    Point _C;

    SideType _sideType;
    AngleType _angleType;

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

    void Classify()
    {
        float AB = sqrt((_B._x - _A._x) * (_B._x - _A._x) + (_B._y - _A._y) * (_B._y - _A._y));
        float BC = sqrt((_C._x - _B._x) * (_C._x - _B._x) + (_C._y - _B._y) * (_C._y - _B._y));
        float AC = sqrt((_C._x - _A._x) * (_C._x - _A._x) + (_C._y - _A._y) * (_C._y - _A._y));
        float order[] = {AB, BC, AC};
        std::sort(order, order + 3);
        AB = order[0];
        BC = order[1];
        AC = order[2];

        // classify side type    
        _sideType = SideType::SCALENE;
        if (AB == BC || AB == AC || BC == AC)
            _sideType = SideType::ISOSCELES;
        if (AB == BC && AB == AC && BC == AC)
            _sideType = SideType::EQUILATERAL;

        // classify angle type
        if (AB * AB + BC * BC == AC * AC)
            _angleType = AngleType::RIGHT;
        else
        {
            if (AB * AB + BC * BC < AC * AC)
                _angleType = AngleType::ACUTE;
            else
                _angleType = AngleType::OBTUSE;
        }

        PrintType();
    }

    void PrintType()
    {
        switch (_sideType)
        {
        case SideType::SCALENE:
            std::cout << "Scalene ";
            break;
        case SideType::ISOSCELES:
            std::cout << "Isosceles ";
            break;
        case SideType::EQUILATERAL:
            std::cout << "Equilateral ";
            break;
        }

        std::cout << "and ";

        switch (_angleType)
        {
        case AngleType::ACUTE:
            std::cout << "Acute ";
            break;
        case AngleType::RIGHT:
            std::cout << "Right angle ";
            break;
        case AngleType::OBTUSE:
            std::cout << "Obtuse ";
            break;
        }

        std::cout << "triangle" << std::endl;
    }

    void PrintAllAngles()
    {
        float AB2 = (_B._x - _A._x) * (_B._x - _A._x) + (_B._y - _A._y) * (_B._y - _A._y);
        float BC2 = (_C._x - _B._x) * (_C._x - _B._x) + (_C._y - _B._y) * (_C._y - _B._y);
        float AC2 = (_C._x - _A._x) * (_C._x - _A._x) + (_C._y - _A._y) * (_C._y - _A._y);

        float AB = sqrt(AB2);
        float BC = sqrt(BC2);
        float AC = sqrt(AC2);

        float alpha =  acos( (BC2 + AC2 - AB2) / (2 * BC * AC) );
        float beta =  acos( (AB2 + AC2 - BC2) / (2 * AB * AC) );
        float gamma =  acos( (AB2 + BC2 - AC2) / (2 * AB * BC) );

        alpha = alpha * 180 / PI;
        beta = beta * 180 / PI;
        gamma = gamma * 180 / PI;

        std::cout << alpha << " " << beta << " " << gamma << std::endl;
    }
};

int main()
{
    Point A(0, 0);
    Point B(0, 1);
    Point C(1, 0);

    Triangle T(A, B, C);
    T.PrintAllAngles();

    return 0;
}