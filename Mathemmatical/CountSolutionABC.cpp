/*
https://www.geeksforgeeks.org/number-non-negative-integral-solutions-b-c-n/

Given a number n, find number of ways we can add 3 non-negative integers so that their sum is n.

Examples :

Input : n = 1
Output : 3
There are three ways to get sum 1.
(1, 0, 0), (0, 1, 0) and (0, 0, 1)

Input : n = 2
Output : 6
There are six ways to get sum 2.
(2, 0, 0), (0, 2, 0), (0, 0, 2), (1, 1, 0)
(1, 0, 1) and (0, 1, 1)

Input : n = 3
Output : 10
There are ten ways to get sum 10.
(3, 0, 0), (0, 3, 0), (0, 0, 3), (1, 2, 0)
(1, 0, 2), (0, 1, 2), (2, 1, 0), (2, 0, 1),
(0, 2, 1) and (1, 1, 1)
*/

#include <iostream>
using namespace std;

int CountSolutionsABC(int n)
{
    return ((n + 1) * (n + 2)) / 2;
}

int main()
{
    int n = 3;
    std::cout << CountSolutionsABC(n) << std::endl;

    return 0;
}