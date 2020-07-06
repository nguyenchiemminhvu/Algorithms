/*
https://www.geeksforgeeks.org/circle-lattice-points/

Given a circle of radius r in 2-D with origin or (0, 0) as center. The task is to find the total lattice points on circumference. Lattice Points are points with coordinates as integers in 2-D space.

Example:

Input  : r = 5.
Output : 12
Below are lattice points on a circle with
radius 5 and origin as (0, 0).
(0,5), (0,-5), (5,0), (-5,0),
(3,4), (-3,4), (-3,-4), (3,-4),
(4,3), (-4,3), (-4,-3), (4,-3).
are 12 lattice point.

To find lattice points, we basically need to find values of (x, y) which satisfy the equation x2 + y2 = r2.
For any value of (x, y) that satisfies the above equation we actually have total 4 different combination which that satisfy the equation.

For example if r = 5 and (3, 4) is a pair which satisfies the equation, there are actually 4 combinations (3, 4) , (-3,4) , (-3,-4) , (3,-4). There is an exception though, in case of (0, r) or (r, 0) there are actually 2 points as there is no negative 0.

// Initialize result as 4 for (r, 0), (-r. 0),
// (0, r) and (0, -r)
result = 4

Loop for x = 1 to r-1 and do following for every x.
    If r*r - x*x is a perfect square, then add 4 
    tor result.  
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

    std::vector<Point> GetLatticePoints()
    {
        std::vector<Point> res;

        for (int x = -(_O._x + _r + 1); x <= (_O._x + _r + 1); x++)
        {
            for (int y = -(_O._y + _r + 1); y <= (_O._y + _r + 1); y++)
            {
                if (x * x + y * y == _r * _r)
                {
                    res.push_back(Point(x, y));
                }
            }
        }

        return res;
    }
};

int main()
{
    Circle c(Point(0.0, 0.0), 5.0);
    
    std::vector<Point> points = c.GetLatticePoints();
    for (Point p : points)
    {
        std::cout << "(" << p._x << "," << p._y << ")" << std::endl;
    }
    
    return 0;
}