/*
https://www.geeksforgeeks.org/count-set-bits-integer-using-lookup-table/

Write an efficient program to count number of 1s in binary representation of an integer.

Examples

Input : n = 6
Output : 2
Binary representation of 6 is 110 
and has 2 set bits

Input : n = 13
Output : 3
Binary representation of 11 is 1101 
and has 3 set bits

In lookup tale, we store count of set_bit of every
number that are in a range (0-255)
LookupTable[0] = 0 | binary 00000000 CountSetBits 0
LookupTable[1] = 1 | binary 00000001 CountSetBits 1
LookupTable[2] = 1 | binary 00000010 CountSetBits 1
LookupTanle[3] = 2 | binary 00000011 CountSetBits 2
LookupTable[4] = 1 | binary 00000100 CountSetBits 1
and so…on upto LookupTable[255].

Let’s take an Example How lookup table work.

Let's number be : 354 
in Binary : 0000000000000000000000101100010

Split it into 8 bits chunks  :
In Binary  :  00000000 | 00000000 | 00000001 | 01100010
In decimal :     0          0          1         98

Now Count Set_bits using LookupTable
LookupTable[0] = 0
LookupTable[1] = 1
LookupTable[98] = 3

so Total bits count : 4 
*/

#include <iostream>
using namespace std;

int CountSetBits(int n)
{
    return 0;
}

int main()
{
    int n = 354;

    std::cout << CountSetBits(n) << std::endl;
    
    return 0;
}