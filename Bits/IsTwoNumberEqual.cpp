#include <iostream>
using namespace std;

bool IsEqual(int a, int b)
{
    return !(a ^ b);
}

int main()
{
    int a = 123, b = 123;

    if (IsEqual(a, b))
        std::cout << "Same" << std::endl;
    else
        std::cout << "Not same" << std::endl;

    return 0;
}