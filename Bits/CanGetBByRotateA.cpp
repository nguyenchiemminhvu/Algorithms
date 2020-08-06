/*
https://www.geeksforgeeks.org/check-two-numbers-bit-rotations-not/

Given two positive integers x and y, check if one integer is obtained by rotating bits of other.

Input constraint: 0 < x, y < 2^32 
Bit Rotation: A rotation (or circular shift) is an operation similar to shift except that the bits that fall off at one end are put back to the other end.

More information on bit rotation can be found here

Example 1 :

Input : a = 8, b = 1
Output : yes

Explanation :
Represntation of a = 8 : 0000 0000 0000 0000 0000 0000 0000 1000
Represntation of b = 1 : 0000 0000 0000 0000 0000 0000 0000 0001
If we rotate a by 3 units right we get b, hence answer is yes

Example 2 :

Input : a = 122, b = 2147483678
Output : yes

Explanation :
Represntation of a = 122        : 0000 0000 0000 0000 0000 0000 0111 1010
Represntation of b = 2147483678 : 1000 0000 0000 0000 0000 0000 0001 1110
If we rotate a by 2 units right we get b, hence answer is yes

Since total bits in which x or y can be represented is 32 since x, y > 0 and x, y < 2^32.
So we need to find all 32 possible rotations of x and compare it with y till x and y are not equal.
To do this we use a temporary variable x64 with 64 bits which is result of concatenation of x to x ie..
x64 has first 32 bits same as bits of x and last 32 bits are also same as bits of x64.

Then we keep on shifting x64 by 1 on right side and compare the rightmost 32 bits of x64 with y.
In this way we'll be able to get all the possible bits combination due to rotation.
*/

#include <iostream>
using namespace std;

bool IsRotation(unsigned int a, unsigned int b)
{
    if (a > b)
        a ^= b ^= a ^= b;
    
    unsigned long long int x64 = a | ((unsigned long long int) a << 32);
    while (x64 >= b)
    {
        if ((unsigned int)x64 == b)
            return true;
        
        x64 >>= 1;
    }

    return false;
}

int main()
{
    unsigned int a = 122;
    unsigned int b = 2147483678;

    if (IsRotation(a, b))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}