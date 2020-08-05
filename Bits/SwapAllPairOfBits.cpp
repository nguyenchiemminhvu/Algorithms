/*
https://www.geeksforgeeks.org/swap-every-two-bits-bytes/

Swap all the pair of bits in a byte. Before swapping: 11-10-11-01 After swapping: 11-01-11-10

Examples:

Input  : 00000010
Output : 00000001

Input  : 00000100
Output : 00001000

Approach:
x = ((x & 0b10101010) >> 1) | ((x & 0b01010101) <> 1 extracts the high bit position and shifts it to the low bit position.
Similarly the expression (x & 0b01010101) << 1 extracts the low bit from each pair and shifts it to the high bit position.
The two parts are then combined using bitwise-OR.
*/

#include <iostream>
using namespace std;

void SwapPairOfBits(int &n)
{
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

int main()
{
    int n = 0b1010;

    std::cout << n << std::endl;
    SwapPairOfBits(n);
    std::cout << n << std::endl;

    return 0;
}