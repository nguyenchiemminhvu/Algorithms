/*
https://www.geeksforgeeks.org/check-given-four-points-form-square/

Given coordinates of four points in a plane, find if the four points form a square or not.
To check for square, we need to check for following.
a) All fours sides formed by points are the same.
b) The angle between any two sides is 90 degree. (This condition is required as Quadrilateral also has same sides.
c) Check both the diagonals have the same distance
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
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

int DistanceSq(Point A, Point B)
{
    return (B._x - A._x) * (B._x - A._x) + (B._y - A._y) * (B._y - A._y);
}

bool IsSquare(Point A, Point B, Point C, Point D)
{
    int AB = DistanceSq(A, B);
    int BC = DistanceSq(B, C);
    int CD = DistanceSq(C, D);
    int DA = DistanceSq(D, A);
    int AC = DistanceSq(A, C);
    int BD = DistanceSq(B, D);

    if (AB == 0 || BC == 0 || CD == 0 || DA == 0)
        return false;
    
    std::vector<int> v = { AB, BC, CD, DA, AC, BD };
    std::sort(v.begin(), v.end());

    std::set<int> s(v.begin(), v.begin() + 4);
    if (s.size() != 1)
        return false;
    
    if (v[0] + v[1] != v[4] && v[2] + v[3] != v[5])
        return false;

    return true;
}

int main()
{
    Point A = { 20, 10 }, B = { 10, 20 }, 
          C = { 20, 20 }, D = { 10, 10 };

    if (IsSquare(A, B, C, D))
    {
        std::cout << "Is square" << std::endl;
    }
    else
    {
        std::cout << "Not a square" << std::endl;
    }
    

    return 0;
}