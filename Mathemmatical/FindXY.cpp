/*
https://www.geeksforgeeks.org/find-x-y-satisfying-ax-n/

Given a, b and n. Find x and y that satisfies ax + by = n. Print any of the x and y satisfying the equation

Examples :

Input : n=7 a=2 b=3
Output : x=2, y=1 
Explanation: here x and y satisfies the equation

Input : 4 2 7 
Output : No solution

solving this equation with pen and paper gives y=(n-ax)/b
and similarly we get the other number to be x=(n-by)/a.
If none of the values satisfies the equation, at the end we print “no solution”.
*/

#include <iostream>
using namespace std;

bool FindXY(int a, int b, int n, int &x, int &y)
{
    for (x = 0; x * a <= n; x++)
    {
        if ((n - (a * x)) % b == 0)
        {
            y = (n - a * x) / b;
            return true;
        }
    }

    return false;
}

int main()
{
    int a = 2, b = 3, n = 7;

    int x, y;
    if (FindXY(a, b, n, x, y))
    {
        std::cout << x << " " << y << std::endl;
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }
    

    return 0;
}