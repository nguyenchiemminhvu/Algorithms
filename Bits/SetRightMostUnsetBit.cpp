/*
https://www.geeksforgeeks.org/set-rightmost-unset-bit/

Given a non-negative number n. The problem is to set the rightmost unset bit in the binary representation of n. If there are no unset bits, then just leave the number as it is.

Examples:

Input : 21
Output : 23
(21)10 = (10101)2
Rightmost unset bit is at position 2(from right) as 
highlighted in the binary representation of 21.
(23)10 = (10111)2
The bit at position 2 has been set.

Input : 15
Output : 15
*/

#include <iostream>
using namespace std;

int GetPosRightMostSetBit(int n)
{
    int pos = 0;

    int m = 1;
    while (!(n & m))
    {
        m <<= 1;
        pos++;
    }

    return pos;
}

void SetRightMostUnsetBit(int &n)
{
    if (n == 0)
    {
        n = 1;
        return;
    }
    if (n == 0xFFFFFFFF)
    {
        return;
    }
    
    int temp = ~n;
    int pos = GetPosRightMostSetBit(temp);

    n = n | (1 << pos);
}

int main()
{
    int n = 0b1001;

    std::cout << n << std::endl;
    SetRightMostUnsetBit(n);
    std::cout << n << std::endl;

    return 0;
}