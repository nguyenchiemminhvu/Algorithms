/*
LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers.
For example LCM of 15 and 20 is 60 and LCM of 5 and 7 is 35.

An efficient solution is based on below formula for LCM of two numbers ‘a’ and ‘b’.

   a x b = LCM(a, b) * GCD (a, b)

   LCM(a, b) = (a x b) / GCD(a, b)
*/

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int a = 15, b = 20;
    std::cout << LCM(a, b) << std::endl;

    return 0;
}