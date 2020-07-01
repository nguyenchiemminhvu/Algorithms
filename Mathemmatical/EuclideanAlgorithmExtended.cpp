/*
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

GCD of two numbers is the largest number that divides both of them. 
A simple way to find GCD is to factorize both numbers and multiply common factors.

Extended Euclidean algorithm also finds integer coefficients x and y such that:

  ax + by = gcd(a, b) 

Examples:

Input: a = 30, b = 20
Output: gcd = 10
        x = 1, y = -1
(Note that 30*1 + 20*(-1) = 10)

Input: a = 35, b = 15
Output: gcd = 5
        x = 1, y = -2
(Note that 35*1 + 15*(-2) = 5)
*/

#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int G = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return G;
}

int main()
{
    int x, y, a = 35, b = 15;
    int g = gcdExtended(a, b, &x, &y);  
    std::cout << "GCD(" << a << ", " << b  << ") = " << g << endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    
    return 0;
}