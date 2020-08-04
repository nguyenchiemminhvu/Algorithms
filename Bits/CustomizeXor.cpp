/*
https://www.geeksforgeeks.org/find-xor-of-two-number-without-using-xor-operator/

1) Find bitwise OR of x and y (Result has set bits where either x has set or y has set bit). OR of x = 3 (011) and y = 5 (101) is 7 (111)

2) To remove extra set bits find places where both x and y have set bits. The value of expression “~x | ~y” has 0 bits wherever x and y both have set bits.

3) bitwise AND of “(x | y)” and “~x | ~y” produces the required result.
*/

#include <iostream>
using namespace std;

int Xor(int a, int b)
{
    return (a | b) & (~a | ~b);
}

int main()
{
    int a = 3, b = 5;
    std::cout << Xor(a, b) << std::endl;

    return 0;
}