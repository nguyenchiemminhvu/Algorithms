/*
Write a program to add one to a given number. The use of operators like ‘+’, ‘-‘, ‘*’, ‘/’, ‘++’, ‘–‘ …etc are not allowed.
Examples:

Input:  12
Output: 13

Input:  6
Output: 7
*/

#include <iostream>
using namespace std;

void AddOne(int &n)
{
    n = (-(~n));
}

int main()
{
    int n = 0b11001101;

    std::cout << n << std::endl;
    AddOne(n);
    std::cout << n << std::endl;

    return 0;
}