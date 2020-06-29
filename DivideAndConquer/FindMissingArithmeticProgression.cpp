/*
https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

Given an array that represents elements of arithmetic progression in order. One element is missing in the progression, find the missing number.
Examples:

Input: arr[]  = {2, 4, 8, 10, 12, 14}
Output: 6

Input: arr[]  = {1, 6, 11, 16, 21, 31};
Output: 26

We can solve this problem in O(Logn) time using Binary Search.
The idea is to go to the middle element.
Check if the difference between middle and next to middle is equal to diff or not,
if not then the missing element lies between mid and mid+1.
If the middle element is equal to n/2th term in Arithmetic Series
(Let n be the number of elements in input array),
then missing element lies in right half.
Else element lies in left half.
*/

#include <iostream>
#include <climits>
using namespace std;

int FindMissingUtility(int * arr, int left, int right, int diff)
{
    if (left >= right)
        return INT_MAX;

    int mid = (left + right) / 2;
    
    if (arr[mid + 1] - arr[mid] != diff)
        return arr[mid] + diff;

    if (arr[mid] - arr[mid - 1] != diff)
        return arr[mid - 1] + diff;

    // If the elements till mid follow AP, then recur for right half 
    if (arr[mid] == arr[0] + mid * diff)
        return FindMissingUtility(arr, mid + 1, right, diff);
    
    // Else recur for left half 
    return FindMissingUtility(arr, left, mid - 1, diff);
}

int FindMissing(int * arr, int n)
{
    int diff = (arr[n - 1] - arr[0]) / n;
    return FindMissingUtility(arr, 0, n - 1, diff);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 14}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = FindMissing(arr, n);
    if (missing == INT_MAX)
    {
        std::cout << "Missing arithmetic progression can not be found" << std::endl;
    }
    else
    {
        std::cout << missing << std::endl;
    }

    return 0;
}