/*
https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/

Given two numbers ‘a’ and b’. Write a program to count number of bits needed to be flipped to convert ‘a’ to ‘b’.
Example :

Input : a = 10, b = 20
Output : 4
Binary representation of a is 00001010
Binary representation of b is 00010100
We need to flip highlighted four bits in a
to make it b.

Input : a = 7, b = 10
Output : 3
Binary representation of a is 00000111
Binary representation of b is 00001010
We need to flip highlighted three bits in a
to make it b.

 1. Calculate XOR of A and B.      
        a_xor_b = A ^ B
  2. Count the set bits in the above 
     calculated XOR result.
        countSetBits(a_xor_b)
XOR of two number will have set bits only at those places where A differs from B.
*/

#include <iostream>
using namespace std;

int CountFlippedBits(int a, int b)
{
    int diff = a ^ b;

    int res = 0;
    while (diff)
    {
        diff = diff & (diff - 1);
        res++;
    }

    return res;
}

int main()
{
    int a = 10;
    int b = 20;

    std::cout << CountFlippedBits(a, b) << std::endl;

    return 0;
}