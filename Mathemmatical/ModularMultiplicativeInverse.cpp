/*
https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.

The modular multiplicative inverse is an integer ‘x’ such that.
 a x ≡ 1 (mod m) 
The value of x should be in {0, 1, 2, … m-1}, i.e., in the range of integer modulo m.

The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

Examples:

Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3(under 11).
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not 
valid.

Input:  a = 10, m = 17
Output: 12
Since (10*12) mod 17 = 1, 12 is modulo inverse of 10(under 17).
*/

#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int G = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return G;
}

int ModInverve(int a, int m)
{
    int x, y;
    int G = gcdExtended(a, m, x, y);
    
    if (G == 1)
    {
        return (x % m + m) % m;
    }
    
    return -1;
}

int main()
{
    int a = 3, m = 11;
    int res = ModInverve(a, m);
    if (res != -1)
    {
        std::cout << res << std::endl;
    }
    else
    {
        std::cout << "Modular inverse doesn't exist" << std::endl;
    }
    return 0;
}