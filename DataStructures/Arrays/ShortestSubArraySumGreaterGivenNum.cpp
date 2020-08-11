/*
https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/

Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.
Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.
*/

#include <iostream>
#include <limits.h>
using namespace std;

int ShortestSubArraySumGreaterGivenNum(int * arr, int n, int sum)
{
    int MinLength = n + 1;

    int CurSum = 0;
    int start = 0, end = 0;

    while (end < n)
    {
        while (CurSum <= sum && end < n)
        {
            CurSum += arr[end];
            end++;
        }

        while (CurSum > sum && start < n)
        {
            if (end - start < MinLength)
                MinLength = end - start;

            CurSum -= arr[start];
            start++;
        }
    }

    return MinLength;
}

int main()
{
    int arr[] = { 1, 4, 45, 6, 10, 19 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 51; 

    std::cout << ShortestSubArraySumGreaterGivenNum(arr, n, sum) << std::endl;

    return 0;
}