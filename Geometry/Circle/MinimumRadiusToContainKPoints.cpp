/*
https://www.geeksforgeeks.org/find-minimum-radius-atleast-k-point-lie-inside-circle/

Given a positive integer K, a circle center at (0, 0) and coordinates of some points. The task is to find minimum radius of the circle so that at-least k points lie inside the circle. Output the square of the minimum radius.

Examples:

Input : (1, 1), (-1, -1), (1, -1), 
         k = 3
Output : 2
We need a circle of radius at least 2
to include 3 points.


Input : (1, 1), (0, 1), (1, -1), 
         k = 2
Output : 1
We need a circle of radius at least 1
to include 2 points. The circle around
(0, 0) of radius 1 would include (1, 1)
and (0, 1).
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

struct Point
{
    float _x;
    float _y;

    Point(float x = 0, float y = 0)
        : _x(x), _y(y)
    {

    }

    Point(const Point &other)
    {
        _x = other._x;
        _y = other._y;
    }

    void Print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }

    double Distance(Point P)
    {
        return sqrt((P._x - _x) * (P._x - _x) + (P._y - _y) * (P._y - _y));
    }

    static int Orientation(Point a, Point b, Point c)
    {
        int val = (b._y - a._y) * (c._x - b._x) - (c._y - b._y) * (b._x - a._x);
        if (val == 0)
            return 0;
        return (val > 0) ? 1 : -1;
    }
};

float MinRadiusToContainKPoint(std::vector<Point> points, int k)
{
    std::vector<float> dist(points.size(), 0);
    for (int i = 0; i < points.size(); i++)
    {
        dist[i] = points[i].Distance(Point(0, 0));
    }

    std::sort(dist.begin(), dist.end());

    return dist[k - 1];
}

int main()
{
    int k = 3;
    std::vector<Point> points = { {1, 1}, {-1, -1}, {2, -1}, {4, 3} };

    std::cout << MinRadiusToContainKPoint(points, k) << std::endl;

    return 0;
}