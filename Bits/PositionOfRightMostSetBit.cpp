#include <iostream>
#include <cmath>
using namespace std;

int PositionOfRightMostSetBit(int n)
{
    int pos = 1;
    
    int m = 1;
    while (!(n & m))
    {
        m <<= 1;
        pos++;
    }
    
    return pos;
}

int main()
{
    int n = 0b110011011000;

    std::cout << PositionOfRightMostSetBit(n) << std::endl;

    return 0;
}