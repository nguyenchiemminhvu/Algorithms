/*
https://www.geeksforgeeks.org/check-number-two-adjacent-set-bits/

Given a number you have to check whether there is pair of adjacent set bit or not.

Examples :

Input : N = 67
Output : Yes
There is a pair of adjacent set bit
The binary representation is 100011

Input : N = 5
Output : No
*/

#include <iostream>
using namespace std;

bool HasTwoAdjacentSetBits(int n)
{
    return (n & (n >> 1)) != 0;
}

int main()
{
    int n = 0b1001001011;

    if (HasTwoAdjacentSetBits(n))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}