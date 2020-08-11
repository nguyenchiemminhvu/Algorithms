/*
https://www.geeksforgeeks.org/find-subarray-least-average/

Given an array arr[] of size n and integer k such that k <= n.
Examples :

Input:  arr[] = {3, 7, 90, 20, 10, 50, 40}, k = 3
Output: Subarray between indexes 3 and 5
The subarray {20, 10, 50} has the least average 
among all subarrays of size 3.

Input:  arr[] = {3, 7, 5, 20, -10, 0, 12}, k = 2
Output: Subarray between [4, 5] has minimum average
*/

#include <iostream>
using namespace std;

float LeastAverageSubArray(int * arr, int n , int k)
{
    if (n < k)
        return 0;
    
    int CurSum = 0;
    for (int i = 0; i < k; i++)
    {
        CurSum += arr[i];
    }

    int MinSum = CurSum;
    for (int i = 1; i < n - k; i++)
    {
        CurSum -= arr[i - 1];
        CurSum += arr[i + k - 1];

        if (MinSum > CurSum)
        {
            MinSum = CurSum;
        }
    }
    
    return (float)MinSum / k;
}

int main()
{
    int arr[] = { 3, 7, 90, 20, 10, 50, 40 };
    int n = sizeof(arr) / sizeof(int);

    int k = 3;
    std::cout << LeastAverageSubArray(arr, n, k) << std::endl;

    return 0;
}