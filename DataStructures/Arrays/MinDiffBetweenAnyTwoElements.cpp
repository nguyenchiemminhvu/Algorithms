/*
https://www.geeksforgeeks.org/find-minimum-difference-pair/

Given an unsorted array, find the minimum difference between any pair in given array.

Examples :

Input  : {1, 5, 3, 19, 18, 25};
Output : 1
Minimum difference is between 18 and 19

Input  : {30, 5, 20, 9};
Output : 4
Minimum difference is between 5 and 9

Input  : {1, 19, -4, 31, 38, 25, 100};
Output : 5
Minimum difference is between 1 and -4
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int MinDiffBetweenAnyTwoElements(int * arr, int n)
{
    std::sort(arr, arr + n);
    
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = std::min(res, arr[i] - arr[i - 1]);
    }

    return res;
}

int main()
{
    int arr[] = {1, 5, 3, 19, 18, 25}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << MinDiffBetweenAnyTwoElements(arr, n) << std::endl;

    return 0;
}