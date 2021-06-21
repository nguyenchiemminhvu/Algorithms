/*
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and using only constant memory space.

Example: 

Input : n = 7 and array[] = {1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6

Explanation: The numbers 1 , 3 and 6 appears more
than once in the array.

Input : n = 5 and array[] = {1, 2, 3, 4 ,3}
Output: 3

Explanation: The number 3 appears more than once
in the array.
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void FindDuplicates(int * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
        {
            std::cout << abs(arr[i]) << std::endl;
        }
        
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }   
}

int main()
{
    int arr[] = { 1, 2, 3, 1, 3, 6, 6, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    FindDuplicates(arr, n);

    return 0;
}