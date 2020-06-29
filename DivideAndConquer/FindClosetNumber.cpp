/*
https://www.geeksforgeeks.org/find-closest-number-array/

Given an array of sorted integers.
We need to find the closest value to the given number.
Array may contain duplicate values and negative numbers.

Examples:

Input : arr[] = {1, 2, 4, 5, 6, 6, 8, 9}
             Target number = 11
Output : 9
9 is closest to 11 in given array

Input :arr[] = {2, 5, 6, 7, 8, 8, 9}; 
       Target number = 4
Output : 5
*/

#include <iostream>
#include <algorithm>
using namespace std;

int GetCloset(int leftNumber, int rightNumber, int target)
{
    if (target - leftNumber <= rightNumber - target)
        return leftNumber;
    
    return rightNumber;
}

int FindClosetNumber(int * arr, int n, int target)
{
    if (target <= arr[0])
        return arr[0];
    
    if (target >= arr[n - 1])
        return arr[n - 1];
    
    // doing binary search
    int left = 0, right = n - 1, mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return arr[mid];
        
        if (arr[mid] > target)
        {
            if (mid > 0 && arr[mid - 1] < target)
                return GetCloset(arr[mid - 1], arr[mid], target);
            
            right = mid - 1;
        }
        else
        {
            if (mid < n - 1 && arr[mid + 1] > target)
                return GetCloset(arr[mid], arr[mid + 1], target);
            
            left = mid + 1;
        }
        
    }
    
    return 0;
}

int main()
{
    int arr[] = { 1, 3, 4, 6, 6, 8, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n); // just make sure the input array is sorted before proceed

    int target = 5;
    int closet = FindClosetNumber(arr, n, target);
    std::cout << closet << std::endl;

    return 0;
}