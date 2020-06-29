/*
You are given a one dimensional array that may contain both positive and negative integers, 
find the sum of contiguous subarray of numbers which has the largest sum.
For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, 
then the maximum subarray sum is 7 (see highlighted elements).

Using Divide and Conquer approach, we can find the maximum subarray sum in O(nLogn) time. Following is the Divide and Conquer algorithm.

1) Divide the given array in two halves
2) Return the maximum of following three
….a) Maximum subarray sum in left half (Make a recursive call)
….b) Maximum subarray sum in right half (Make a recursive call)
….c) Maximum subarray sum such that the subarray crosses the midpoint
*/

#include <iostream>
using namespace std;

int MaxSubArraySumUtility(int * arr, int left, int right)
{
    return 0;
}

int MaxSubArraySum(int * arr, int n)
{
    return MaxSubArraySumUtility(arr, 0, n - 1);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << MaxSubArraySum(arr, n) << std::endl;

    return 0;
}