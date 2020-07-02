/*
https://www.geeksforgeeks.org/find-last-digit-in-factorial/

Given a number n, we need to find the last digit in factorial n.

Input : n = 4
Output : 4
4! = 4 * 3 * 2 * 1. =  24.  Last digit of 24 is 4.

Input : n = 5
Output : 5
5! = 5*4 * 3 * 2 * 1. =  120.  Last digit of 120 is 0.

A Naive Solution is to first compute fact = n!, then return the last digit of the result by doing fact % 10.  This solution is inefficient and causes integer overflow for even slightly large value of n.

An Efficient Solution is based on the observation that all factorials after 5 have 0 as last digit.
*/

#include <iostream>
using namespace std;

int LastDigitOfFactorial(int n)
{
    if (n == 0) return 1;
    if (n <= 2) return n;
    if (n == 3) return 6;
    if (n == 4) return 4;
    
    return 0;
}

int main()
{
    std::cout << LastDigitOfFactorial(6) << std::endl;
    return 0;
}