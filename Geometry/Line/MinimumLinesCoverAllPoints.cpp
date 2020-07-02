/*
https://www.geeksforgeeks.org/minimum-lines-cover-points/

Given N points in 2-dimensional space, we need to print the count of the minimum number of lines which traverse through all these N points and which go through a specific (xO, yO) point also.

Examples:

If given points are (-1, 3), (4, 3), (2, 1), (-1, -2), 
(3, -3) and (xO, yO) point is (1, 0) i.e. every line
must go through this point. 
Then we have to draw at least two lines to cover all
these points going through (xO, yO).

We can solve this problem by considering the slope of all points with (xO, yO).
If two distinct points have the same slope with (xO, yO)
then they can be covered with same line only so we can track slope of each point
and whenever we get a new slope we will increase our line count by one.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

void GetReducedForm(int dy, int dx, std::pair<int, int> &reduced)
{
    cout << abs(dy) << " " << abs(dx) << endl;
    int G = GCD(abs(dy), abs(dx));

    bool sign = (dy < 0) ^ (dx < 0);
    if (sign)
        reduced = std::pair<int, int>(-abs(dy) / G, abs(dx) / G);
    else
        reduced = std::pair<int, int>(abs(dy) / G, abs(dx) / G);
}

int MinimumLinesCoverAllPoints(std::vector<Point> points, Point P0)
{
    std::set<std::pair<int, int>> S;
    
    std::pair<int, int> temp;
    for (int i = 0; i < points.size(); i++)
    {
        int curX = points[i]._x;
        int curY = points[i]._y;

        GetReducedForm(curY - P0._y, curX - P0._x, temp);
        S.insert(temp);
    }

    return S.size();
}

int main()
{
    Point P0 = { 1, 0 };
    std::vector<Point> points = 
    {
        {-1, 3}, 
        {4, 3}, 
        {2, 1}, 
        {-1, -2}, 
        {3, -3} 
    };

    std::cout << MinimumLinesCoverAllPoints(points, P0) << std::endl;

    return 0;
}