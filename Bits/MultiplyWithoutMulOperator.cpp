/*
https://www.geeksforgeeks.org/multiplication-two-numbers-shift-operator/

For any given two numbers n and m, you have to find n*m without using any multiplication operator.

Examples :

Input: n = 25 , m = 13
Output: 325

Input: n = 50 , m = 16
Output: 800

We can solve this problem with the shift operator. The idea is based on the fact that every number can be represented in binary form. And multiplication with a number is equivalent to multiplication with powers of 2. Powers of 2 can be obtained using left shift operator.

Check for every set bit in the binary representation of m and for every set bit left shift n, count times where count if place value of the set bit of m and add that value to answer.
*/

#include <iostream>
using namespace std;

int Multiply(int a, int b)
{
    int res = 0;
    
    int count = 0;
    while (b)
    {
        if (b & 1)
            res += (a << count);

        count++;
        b >>= 1;
    }

    return res;
}

int main()
{
    int a = 25;
    int b = 13;

    std::cout << Multiply(a, b) << std::endl;

    return 0;
}