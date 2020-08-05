/*
https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/

Given an unsigned integer, reverse all bits of it and return the number with reversed bits.

Input : n = 1
Output : 2147483648  
On a machine with size of unsigned
bit as 32. Reverse of 0....001 is
100....0.

Input : n = 2147483648
Output : 1             
*/

#include <iostream>
using namespace std;

void ReverseBits(unsigned int &n)
{
    n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

int main()
{
    unsigned int n = 1;
    
    std::cout << n << std::endl;
    ReverseBits(n);
    std::cout << n << std::endl;

    return 0;
}