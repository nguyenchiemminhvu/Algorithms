/*
https://www.geeksforgeeks.org/efficient-way-to-multiply-with-7/#:~:text=We%20can%20multiply%20a%20number,CPP

We can multiply a number by 7 using bitwise operator. First left shift the number by 3 bits (you will get 8n) then subtract the original numberfrom the shifted number and return the difference (8n – n).
*/

#include <iostream>
using namespace std;

void MultiplyWith7(int &n)
{
    n = (n << 3) - n;
}

int main()
{
    int n = 7;

    std::cout << n << std::endl;
    MultiplyWith7(n);
    std::cout << n << std::endl;

    return 0;
}