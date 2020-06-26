/*
Given two integers x and n, write a function to compute pow(x, n). 
We may assume that x and n are small and overflow doesn’t happen.

Examples :

Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49
*/

#include <iostream>
using namespace std;

float Pow(float x, int n)
{
    if (n == 0)
        return 1;
    
    float temp = Pow(x, n / 2);
    if (n & 1)
    {
        if (n > 0)
            return x * temp * temp;
        else
            return temp * temp / x;
    }
    else
    {
        return temp * temp;
    }
}

int main()
{
    float x = 2;
    int n = -3;

    std::cout << Pow(x, n) << std::endl;

    return 0;
}