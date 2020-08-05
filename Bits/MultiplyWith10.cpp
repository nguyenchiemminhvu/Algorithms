/*
https://www.geeksforgeeks.org/multiply-number-10-without-using-multiplication-operator/

Given a number, the task is to multiply it with 10 without using multiplication operator?

Examples:

Input : n = 50
Output: 500
// multiplication of 50 with 10 is = 500

Input : n = 16
Output: 160
// multiplication of 16 with 10 is = 160

We have to multiply n with 10 i.e; n*10, we can write this as n*(2+8) = n*2 + n*8 and since we are not allowed to use multiplication operator we can do this using left shift bitwise operator. So n*10 = n<<1 + n<<3.
*/

#include <iostream>
using namespace std;

void MultiplyWith10(int &n)
{
    n = (n << 3) + (n << 1);
}

int main()
{
    int n = 25;

    std::cout << n << std::endl;
    MultiplyWith10(n);
    std::cout << n << std::endl;

    return 0;
}