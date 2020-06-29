/*
https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/

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
#include <algorithm>
#include <climits>
using namespace std;

int Max(int a, int b, int c)
{
    return std::max(a, std::max(b, c));
}

int MaxSubArrayCrossingSum(int * arr, int left, int mid, int right)
{
    int sum;

    sum = 0;
    int leftSum = INT16_MIN;
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT16_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return Max(leftSum + rightSum, leftSum, rightSum);
}

int MaxSubArraySum(int * arr, int left, int right)
{
    if (left == right)
        return arr[left];
    
    int mid = (left + right) / 2;
    return Max(
        MaxSubArraySum(arr, left, mid), 
        MaxSubArraySum(arr, mid + 1, right), 
        MaxSubArrayCrossingSum(arr, left, mid, right)
    );
}

int main()
{
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int n = sizeof(arr) / sizeof(int);

    std::cout << MaxSubArraySum(arr, 0, n - 1) << std::endl;

    return 0;
}