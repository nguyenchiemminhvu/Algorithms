/*
https://www.geeksforgeeks.org/find-the-element-that-appears-once/

Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
Examples :

Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
In the given array all element appear three times except 2 which appears once.

Input: arr[] = {10, 20, 10, 30, 10, 30, 30}
Output: 20
In the given array all element appear three times except 20 which appears once.


*/

#include <iostream>
using namespace std;

int FindElementAppearOnce(int * arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= arr[i];
    }

    return res;
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << FindElementAppearOnce(arr, n) << std::endl;

    return 0;
}