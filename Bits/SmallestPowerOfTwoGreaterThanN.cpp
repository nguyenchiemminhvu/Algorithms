/*
https://www.geeksforgeeks.org/smallest-power-of-2-greater-than-or-equal-to-n/

Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a smallest power of 2.
Examples :

    Input : n = 5
    Output: 8     

    Input  : n = 17
    Output : 32     

    Input  : n = 32
    Output : 32     
*/

#include <iostream>
using namespace std;

bool IsPowerOfTwo(int n)
{
    return !(n & (n - 1));
}

int SmallestPowerOfTwoGreaterOrEqualN(int n)
{
    if (IsPowerOfTwo(n))
        return n;

    n = (n | (n >> 1));
    n = (n | (n >> 2));
    n = (n | (n >> 4));
    n = (n | (n >> 8));
    n = (n | (n >> 16));

    return n + 1;
}

int main()
{
    int n = 32;
    std::cout << SmallestPowerOfTwoGreaterOrEqualN(n) << std::endl;

    return 0;
}