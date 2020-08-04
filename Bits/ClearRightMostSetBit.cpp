#include <iostream>
using namespace std;

void ClearRightMostSetBit(int &num)
{
    num = num & (num - 1);
}

int main()
{
    int n = 0b101;
    
    ClearRightMostSetBit(n);
    std::cout << n << std::endl;

    return 0;
}