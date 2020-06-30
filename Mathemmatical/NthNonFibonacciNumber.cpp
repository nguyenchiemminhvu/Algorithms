/*
https://www.geeksforgeeks.org/nth-non-fibonacci-number/

Given a positive integer n, the task is to print the n’th non Fibonacci number. The Fibonacci numbers are defined as:

Fib(0) = 0
Fib(1) = 1
for n >1, Fib(n) = Fib(n-1) + Fib(n-2)
First few Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ……..

Examples :

Input : n = 2
Output : 6

Input : n = 5
Output : 10
*/

#include <iostream>
using namespace std;

int NthNonFibonacciNumber(int nth)
{
    int a = 1, b = 2, c = 3;
    while (nth > 0)
    {
        a = b;
        b = c;
        c = a + b;
        nth = nth - (c - b - 1);
    }

    nth = nth + (c - b - 1);
    return b + nth;
}

int main()
{
    int nth = 10;
    std::cout << NthNonFibonacciNumber(nth) << std::endl;

    return 0;
}