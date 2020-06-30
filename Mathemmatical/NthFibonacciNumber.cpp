/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

    Fn = Fn-1 + Fn-2
with seed values

   F0 = 0 and F1 = 1.

Given a number n, print n-th Fibonacci Number.
Examples:

Input  : n = 2
Output : 1

Input  : n = 9
Output : 34
*/

#include <iostream>
using namespace std;

int NthFibonacciNumber(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    
    return NthFibonacciNumber(n - 2) + NthFibonacciNumber(n - 1);
}

int main()
{
    int nth = 10;
    std::cout << NthFibonacciNumber(nth) << std::endl;
    
    return 0;
}