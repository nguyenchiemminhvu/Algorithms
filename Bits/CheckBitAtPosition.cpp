/*
It is quite easily doable using ‘AND’ operator.
Left shift ‘1’ to given position and then ‘AND'(‘&’).
*/

#include <iostream>
using namespace std;

bool CheckBit(int num, int pos)
{
    bool b = num & (1 << pos);
    return b;
}

int main()
{
    int n = 0b11001001;
    int pos = 3;

    if (CheckBit(n, pos))
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;
    
    return 0;
}