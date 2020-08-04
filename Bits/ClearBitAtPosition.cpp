/*
Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.

First we left shift ‘1’ to n position via (1<<n) than we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position position.
*/

#include <iostream>
using namespace std;

void ClearBit(int &num, int pos)
{
    num &= (~(1 << pos));
}

int main()
{
    int n = 0b111111;
    
    ClearBit(n, 5);
    std::cout << n << std::endl;

    return 0;
}