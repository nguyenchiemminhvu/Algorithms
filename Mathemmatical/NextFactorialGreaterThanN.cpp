/*
https://www.geeksforgeeks.org/find-the-next-factorial-greater-than-n/

Given a number N (≤ 1018), the task is to find the next factorial number greater than N.

Examples:

Input: N = 24
Output: 120
Explanation:
As 4! = 24. So the next number which factorial and greater than 24 is 5!, which is 120

Input: N = 150
Output: 720
Explanation:
As 5! = 120. So the next number which factorial and greater than 150 is 6!, which is 720.
*/

#include <iostream>
using namespace std;

long long int fact[21];

void PreComputeFactorialUpTo20()
{
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fact[i] = (fact[i - 1] * i);
    }
}

long long int NextFactorialGreaterThan(long long int n)
{
    for (int i = 0; i <= 20; i++)
    {
        if (fact[i] > n)
            return fact[i];
    }

    return -1;
}

int main()
{
    PreComputeFactorialUpTo20();
    std::cout << NextFactorialGreaterThan(121645100408832000) << std::endl;
    return 0;
}