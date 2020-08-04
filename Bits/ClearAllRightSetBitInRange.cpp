#include <iostream>
using namespace std;

void ClearAllSetBitInRange(int &num, int range)
{
    int mask = ~((1 << range) - 1);
    num &= mask;
}

int main()
{
    int n = 0b1101;
    int range = 3;

    ClearAllSetBitInRange(n, range);
    std::cout << n << std::endl;

    return 0;
}