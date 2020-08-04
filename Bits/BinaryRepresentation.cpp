#include <iostream>
#include <string>
using namespace std;

std::string ToBinary(int n)
{
    std::string res;
    while (n)
    {
        res += (n & 1) ? "1" : "0";
        n >>= 1;
    }

    return std::string(res.rbegin(), res.rend());
}

int main()
{
    int n = 7;

    std::cout << ToBinary(n) << std::endl;

    return 0;
}