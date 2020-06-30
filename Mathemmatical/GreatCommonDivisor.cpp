/*
https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/

GCD (Greatest Common Divisor) of two numbers is the largest number that divides both of them.

An efficient solution is to use Euclidean algorithm
which is the main algorithm used for this purpose.
The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.

A more efficient solution is to use modulo operator in Euclidean algorithm .
*/

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
}

int main()
{
    int a = 15, b = 20;
    std::cout << GCD(a, b) << std::endl;

    return 0;
}
