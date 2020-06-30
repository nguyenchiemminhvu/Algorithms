/*
Given an unsorted array arr[] and an integer K, the task is to count the occurrences of K in the given array using Divide and Conquer method.

Examples:

Input: arr[] = {1, 1, 2, 2, 2, 2, 3}, K = 1
Output: 2

Input: arr[] = {1, 1, 2, 2, 2, 2, 3}, K = 4
Output: 0

Approach:

The idea is to divide the array into two parts of equal sizes
and count the number of occurrences of K in each half and then add them up.

Divide the array into two parts until there is only one element left in the array.
Check that single element in the array is K or not, If it is K then return 1 otherwise 0.
Add up the returned values for each of the element to find the occurence of K in the whole array.
*/

#include <iostream>
using namespace std;

int FrequencyOfElement(int * arr, int left, int right, int x)
{
    if (left > right)
        return 0;
    
    if (left == right && arr[left] != x)
        return 0;
    
    if (left == right && arr[left] == x)
        return 1;

    int mid = (left + right) / 2;
    return FrequencyOfElement(arr, left, mid, x) + FrequencyOfElement(arr, mid + 1, right, x);
}

int main()
{
    int arr[] = { 30, 1, 42, 5, 56, 3, 56, 9 };
    int n = sizeof(arr) / sizeof(int);
    int x = 56;

    std::cout << FrequencyOfElement(arr, 0, n - 1, x) << std::endl;

    return 0;
}