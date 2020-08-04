#include <iostream>
using namespace std;

void ClearLeftMostSetBit(int &num)
{
    num = num & (num - 1);
}

int main()
{
    int n = 0b101;
    
    ClearLeftMostSetBit(n);
    std::cout << n << std::endl;

    return 0;
}