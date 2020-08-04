/*
If we want to set a bit at nth position in number ‘num’ ,it can be done using ‘OR’ operator( | ).

First we left shift ‘1’ to n position via (1<<n)
Then, use ‘OR’ operator to set bit at that position.’OR’ operator is used because it will set the bit even if the bit is unset previously in binary representation of number ‘num’.
*/

#include <iostream>
using namespace std;

void SetBit(int &num, int pos)
{
    num |= (1 << pos);
}

int main()
{
    int n = 0;

    SetBit(n, 3);
    std::cout << n << std::endl;

    return 0;
}