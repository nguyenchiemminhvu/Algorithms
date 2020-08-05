/*
https://www.geeksforgeeks.org/how-to-swap-two-bits-in-a-given-integer/

Given an integer n and two bit positions p1 and p2 inside it, swap bits at the given positions. The given positions are from least significant bit (lsb). For example, the position for lsb is 0.
Examples:

Input: n = 28, p1 = 0, p2 = 3
Output: 21
28 in binary is 11100.  If we swap 0'th and 3rd digits, 
we get 10101 which is 21 in decimal.

Input: n = 20, p1 = 2, p2 = 3
Output: 24
*/

#include <iostream>
using namespace std;

void SwapTwoBits(int &n, int p1, int p2)
{
    int t1 = ((n >> p1) & 1);
    int t2 = ((n >> p2) & 1);

    int x = t1 ^ t2;
    x = (x << p1) | (x << p2);

    n ^= x;
}

int main()
{
    int n = 28;
    int p1 = 0, p2 = 3;

    std::cout << n << std::endl;
    SwapTwoBits(n, p1, p2);
    std::cout << n << std::endl;

    return 0;
}