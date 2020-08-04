#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    a ^= b ^= a ^= b;
}

int main()
{
    int a = 10;
    int b = 5;

    std::cout << a << " " << b << std::endl;
    Swap(a, b);
    std::cout << a << " " << b << std::endl;

    return 0;
}