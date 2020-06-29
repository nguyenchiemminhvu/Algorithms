/*
https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative.

Examples:

  Input: arr[] = {-10, -5, 0, 3, 7}
  Output: 3  // arr[3] == 3 

  Input: arr[] = {0, 2, 5, 8, 17}
  Output: 0  // arr[0] == 0 


  Input: arr[] = {-10, -5, 3, 4, 7, 9}
  Output: -1  // No Fixed Point

First check whether middle element is Fixed Point or not.
If it is, then return it; otherwise check whether index of middle element is greater than value at the index. 
If index is greater, then Fixed Point(s) lies on the right side of the middle point (obviously only if there is a Fixed Point).
Else the Fixed Point(s) lies on left side.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int FindFixedPoint(int * arr, int left, int right)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == mid)
            return mid;
        
        if (arr[mid] < mid)
        {
            return FindFixedPoint(arr, mid + 1, right);
        }
        else
        {
            return FindFixedPoint(arr, left, mid - 1);
        }
    }

    return -1;
}

int main()
{
    int arr[] = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };  
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n); // just make sure input array be sorted before proceed

    int fixedPoint = FindFixedPoint(arr, 0, n - 1);
    if (fixedPoint == -1)
    {
        std::cout << "There is no fixed point" << std::endl;
    }
    else
    {
        std::cout << fixedPoint << std::endl;
    }
    

    return 0;
}