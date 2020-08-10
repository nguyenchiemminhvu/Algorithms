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
#include <vector>
using namespace std;

#define BIT(n) n, n + 1, n + 1, n + 2, n + 1, n + 2, n + 2, n + 3, n + 1, n + 2, n + 2, n + 3, n + 2, n + 3, n + 3, n + 4
#define BITS BIT(0), BIT(1), BIT(1), BIT(2), BIT(1), BIT(2), BIT(2), BIT(3), BIT(1), BIT(2), BIT(2), BIT(3), BIT(2), BIT(3), BIT(3), BIT(4)

static unsigned char SetBitsInUChar[] =
{
    BITS
};

int CountSetBits(int n)
{
    return SetBitsInUChar[n & 0xFF]
         + SetBitsInUChar[(n >> 8) & 0xFF]
         + SetBitsInUChar[(n >> 16) & 0xFF]
         + SetBitsInUChar[(n >> 24) & 0xFF];
}

int main()
{
    std::vector<int> test = { 333, 352, 777, 177, 102, 35, 32, 31 };
    std::vector<int> v;

    for (int n : test)
    {
        v.push_back(CountSetBits(n));
    }

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
    return 0;
}