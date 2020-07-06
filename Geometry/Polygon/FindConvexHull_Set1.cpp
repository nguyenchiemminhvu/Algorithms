/*
https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/

Given a set of points in the plane.
The convex hull of the set is the smallest convex polygon that contains all the points of it.

The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) and we keep wrapping points in counterclockwise direction. The big question is, given a point p as current point, how to find the next point in output? The idea is to use orientation() here. Next point is selected as the point that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, we have “orientation(p, q, r) = counterclockwise”. Following is the detailed algorithm.

1) Initialize p as leftmost point.
2) Do following while we don’t come back to the first (or leftmost) point.
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r.
…..b) next[p] = q (Store q as next of p in the output convex hull).
…..c) p = q (Set p as q for next iteration).

Time Complexity:
For every point on the hull we examine all the other points to determine the next point.
Time complexity is (m * n) where n is number of input points and m is number of output or hull points (m <= n).
In worst case, time complexity is O(n 2).
The worst case occurs when all the points are on the hull (m = n)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
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

int Orientation(Point a, Point b, Point c)
{
    int val = (b._y - a._y) * (c._x - b._x) - (c._y - b._y) * (b._x - a._x);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : -1;
}

void FindConvexHull(Point * points, int n, std::vector<Point> &hull)
{
    if (n < 3)
        return;

    // Find leftmost point
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i]._x < points[left]._x)
        {
            left = i;
        }
    }

    
}

int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    std::vector<Point> hull;
    FindConvexHull(points, n, hull);

    if (hull.empty())
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        for (Point p : hull)
        {
            p.Print();
        }   
    }

    return 0;
}