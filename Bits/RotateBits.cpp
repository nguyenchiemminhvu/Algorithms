#include <iostream>
using namespace std;

#define INT_BITS 32

void RotateLeft(int &n, int d)
{
    n = (n << d) | (n >> (INT_BITS - d));
}

void RotateRight(int &n, int d)
{
    n = (n >> d) | (n << (INT_BITS - d));
}

int main()
{
    int n = 0b11101101101;

    std::cout << n << std::endl;
    RotateLeft(n, 3);
    std::cout << n << std::endl;
    RotateRight(n, 3);
    std::cout << n << std::endl;

    return 0;
}