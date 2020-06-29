/*
https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/

We are given an array of n points in the plane,
and the problem is to find out the closest pair of points in the array.
This problem arises in a number of applications.
For example, in air-traffic control, you may want to monitor planes that come too close together,
since this may indicate a possible collision.
Recall the following formula for distance between two points p and q.

|pq| = sqrt{ (p{x} - q{x}) ^ {2} + (p{y} - q{y}) ^ {2} } 

Algorithm:

1) Find the middle point in the sorted array, we can take P[n/2] as middle point.

2) Divide the given array in two halves. 
The first subarray contains points from P[0] to P[n/2]. 
The second subarray contains points from P[n/2+1] to P[n-1].

3) Recursively find the smallest distances in both subarrays. 
Let the distances be dl and dr. Find the minimum of dl and dr. 
Let the minimum be d.

4) From the above 3 steps, we have an upper bound d of minimum distance. 
Now we need to consider the pairs such that one point in pair is from the left half and 
the other is from the right half. Consider the vertical line passing through P[n/2] and find all points 
whose x coordinate is closer than d to the middle vertical line. Build an array strip[] of all such points.

5) Sort the array strip[] according to y coordinates. 
This step is O(nLogn). 
It can be optimized to O(n) by recursively sorting and merging.

6) Find the smallest distance in strip[]. 
This is tricky. 
From the first look, it seems to be a O(n^2) step, but it is actually O(n). 
It can be proved geometrically that for every point in the strip,
we only need to check at most 7 points after it (note that strip is sorted according to Y coordinate). 

7) Finally return the minimum of d and distance calculated in the above step (step 6)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std;

struct Point
{
    int _x;
    int _y;

    Point()
        : _x(0), _y(0)
    {

    }

    Point(int x, int y)
        : _x(x), _y(y)
    {

    }

    float Distance(const Point &p)
    {
        return sqrt((_x - p._x) * (_x - p._x) + (_y - p._y) * (_y - p._y));
    }
};

int CompareX(const Point &p1, const Point &p2)
{
    return p1._x < p2._x;
}

int CompareY(const Point &p1, const Point &p2)
{
    return p1._y < p2._y;
}

float BruteForce(const std::vector<Point> &points, Point check)
{
    float M = FLT_MAX;

    for (Point p : points)
    {
        M = std::min(M, check.Distance(p));
    }
    
    return M;
}

float FindClosetPointUtility(std::vector<Point> Px, std::vector<Point> Py, Point check)
{
    if (Px.size() <= 3)
        return BruteForce(Px, check);
    
    int mid = Px.size() / 2;

    std::vector<Point> PxLeft(mid);
    std::vector<Point> PxRight(Px.size() - mid);
    std::vector<Point> PyLeft(mid);
    std::vector<Point> PyRight(Py.size() - mid);
    int iLeft = 0;
    int iRight = 0;
    
    for (Point p : Py)
    {
        if (p._x <= Py[mid]._x && iLeft < mid)
        {
            PxLeft[iLeft] = p;
            PyLeft[iLeft++] = p;
        }
        else
        {
            PxRight[iRight] = p;
            PyRight[iRight++] = p;
        }
    }

    float dLeft = FindClosetPointUtility(PxLeft, PyLeft, check);
    float dRight = FindClosetPointUtility(PxRight, PyRight, check);

    float d = std::min(dLeft, dRight);
    return d;
}

float FindClosetPoint(std::vector<Point> points, Point check)
{
    std::vector<Point> Px(points.begin(), points.end());
    std::vector<Point> Py(points.begin(), points.end());
    std::sort(Px.begin(), Px.end(), CompareX);
    std::sort(Py.begin(), Py.end(), CompareY);

    return FindClosetPointUtility(Px, Py, check);
}

int main()
{
    std::vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    Point check = Point(0, 0);

    std::cout << FindClosetPoint(points, check) << std::endl;

    return 0;
}