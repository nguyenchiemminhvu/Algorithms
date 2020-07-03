/*
https://www.geeksforgeeks.org/program-to-find-the-type-of-triangle-from-the-given-coordinates/

We are given coordinates of a triangle. The task is to classify this triangle on the basis of sides and angle.

Examples:

Input: p1 = (3, 0), p2 = (0, 4), p3 = (4, 7)
Output: Right Angle triangle and Isosceles

Input: p1 = (0, 0), p2 = (1, 1), p3 = (1, 2);
Output: Triangle is obtuse and Scalene
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
};

int main()
{
    Point A(3, 0);
    Point B(0, 4);
    Point C(4, 7);

    Triangle T(A, B, C);
    T.Classify();
    T.PrintType();

    return 0;
}