/*
Given a number ‘n’, how to check if n is a Fibonacci number.
First few Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ..

Examples :

Input : 8
Output : Yes

Input : 34
Output : Yes

Input : 41
Output : No

A simple way is to generate Fibonacci numbers until the generated number is greater than or equal to ‘n’.

Following is an interesting property about Fibonacci numbers
that can also be used to check if a given number is Fibonacci or not:

A number is Fibonacci if and only if one or both of 
(5*n2 + 4) or (5*n2 – 4) is a perfect square (Source: Wiki).
*/

#include <iostream>
#include <cmath>
using namespace std;

bool IsPerfectSquare(int n)
{
    int t = sqrt(n);
    return (t * t == n);
}

bool IsFibonacciNumber(int n)
{
    return IsPerfectSquare(5 * n * n + 4) || IsPerfectSquare(5 * n * n - 4);
}

int main()
{
    int n = 34;
    if (IsFibonacciNumber(n))
    {
        std::cout << "A fibonacci number" << std::endl;
    }
    else
    {
        std::cout << "Not a fibonacci number" << std::endl;
    }
    
    return 0;
}