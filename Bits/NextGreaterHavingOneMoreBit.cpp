/*
https://www.geeksforgeeks.org/next-greater-integer-one-number-set-bits/

Given a positive integer ‘n’ having ‘x’ number of set bits in its binary representation. The problem is to find the next greater integer(smallest integer greater than n), having (x+1) number of set bits in its binary representation.


Examples :

Input : 10
Output : 11
(10)10 = (1010)2
is having 2 set bits.

(11)10 = (1011)2
is having 3 set bits and is the next greater.

Input : 39
Output : 47
*/

#include <iostream>
using namespace std;

int NextGreaterHavingOneMoreBit(int n)
{
    int m = 1;
    while (n & m)
    {
        m <<= 1;
    }

    n |= m;

    return n;
}

int main()
{
    int n = 39;
    
    std::cout << NextGreaterHavingOneMoreBit(n) << std::endl;

    return 0;
}