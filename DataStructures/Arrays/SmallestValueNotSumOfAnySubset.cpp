/*
https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

Given a sorted array (sorted in non-decreasing order) of positive numbers, find the smallest positive integer value that cannot be represented as sum of elements of any subset of given set.
Expected time complexity is O(n).

Examples:

Input:  arr[] = {1, 3, 6, 10, 11, 15};
Output: 2

Input:  arr[] = {1, 1, 1, 1};
Output: 5

Input:  arr[] = {1, 1, 3, 4};
Output: 10

Input:  arr[] = {1, 2, 5, 10, 20, 40};
Output: 4

Input:  arr[] = {1, 2, 3, 4, 5, 6};
Output: 22
*/

#include <iostream>
using namespace std;

int SmallestValueNotSumOfAnySubset(int * arr, int n)
{
    int res = 1;

    for (int i = 0; i < n && arr[i] <= res; i++)
    {
        res += arr[i];
    }

    return res;
}

int main()
{
    int arr1[] = {1, 3, 4, 5}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    std::cout << SmallestValueNotSumOfAnySubset(arr1, n1) << std::endl; 

    int arr2[] = {1, 2, 6, 10, 11, 15}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    std::cout << SmallestValueNotSumOfAnySubset(arr2, n2) << std::endl; 

    int arr3[] = {1, 1, 1, 1}; 
    int n3 = sizeof(arr3) / sizeof(arr3[0]); 
    std::cout << SmallestValueNotSumOfAnySubset(arr3, n3) << std::endl; 

    int arr4[] = {1, 1, 3, 4}; 
    int n4 = sizeof(arr4) / sizeof(arr4[0]); 
    std::cout << SmallestValueNotSumOfAnySubset(arr4, n4) << std::endl;

    return 0;
}