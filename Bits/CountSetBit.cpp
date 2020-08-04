/*
https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

Write an efficient program to count number of 1s in binary representation of an integer.

Examples :

Input : n = 6
Output : 2
Binary representation of 6 is 110 and has 2 set bits

Input : n = 13
Output : 3
Binary representation of 13 is 1101 and has 3 set bits
*/

#include <iostream>
using namespace std;

int CountSetBit(int num)
{
    int res = 0;
    while (num)
    {
        num &= (num - 1);
        res++;
    }
    return res;
}

int main()
{
    int n = 0b111001001;

    std::cout << CountSetBit(n) << std::endl;    

    return 0;
}