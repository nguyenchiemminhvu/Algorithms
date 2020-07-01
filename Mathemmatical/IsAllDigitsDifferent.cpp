/*
A number is lucky if all digits of the number are different. How to check if a given number is lucky or not.
Examples:

Input: n = 983
Output: true
All digits are different

Input: n = 9838
Output: false
8 appears twice
*/

#include <iostream>
using namespace std;

bool IsAllDigitsDifferent(int n)
{
    int freq[10] = { 0 };
    while (n)
    {
        freq[n % 10]++;
        n /= 10;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (freq[i] > 1)
            return false;
    }

    return true;
}

int main()
{
    int arr[] = { 1291, 897, 4566, 1232, 80, 700 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (IsAllDigitsDifferent(arr[i]))
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}