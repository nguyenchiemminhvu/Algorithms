/*
https://www.geeksforgeeks.org/calculate-xor-1-n/

Given a number n, the task is to find the XOR from 1 to n.

Examples :

Input : n = 6
Output : 7
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6  = 7

Input : n = 7
Output : 0
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0

Method 1 (Naive Approach):
1- Initialize result as 0.
1- Traverse all numbers from 1 to n.
2- Do XOR of numbers one by one with result.
3- At the end, return result.

Method 2 (Efficient method) :
1- Find the remainder of n by moduling it with 4.
2- If rem = 0, then xor will be same as n.
3- If rem = 1, then xor will be 1.
4- If rem = 2, then xor will be n+1.
5- If rem = 3 ,then xor will be 0.
*/

#include <iostream>
using namespace std;

int XorFrom1ToN(int n)
{
    switch (n % 4)
    {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }

    return 0;
}

int main()
{
    int n = 6;
    std::cout << XorFrom1ToN(n) << std::endl;

    return 0;
}