/*
Logic: All the power of 2 have only single bit set e.g. 16 (00010000). If we minus 1 from this, all the bits from LSB to set bit get toggled, i.e., 16-1 = 15 (00001111). Now if we AND x with (x-1) and the result is 0 then we can say that x is power of 2 otherwise not. We have to take extra care when x = 0.

Example
x = 16(000100000)
x – 1 = 15(00001111)
x & (x-1) = 0
so 16 is power of 2
*/

#include <iostream>
using namespace std;

bool IsPowerOfTwo(int n)
{
    return !(n & (n - 1));
}

int main()
{
    int n = 32;

    if (IsPowerOfTwo(n))
        std::cout << "Power of two" << std::endl;
    else
        std::cout << "Not power of two" << std::endl;
    
    return 0;
}