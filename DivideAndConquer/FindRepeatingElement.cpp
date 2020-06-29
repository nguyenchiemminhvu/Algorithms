/*
https://www.geeksforgeeks.org/find-repeating-element-sorted-array-size-n/

Given a sorted array of n elements containing elements in range from 1 to n-1 i.e. one element occurs twice, the task is to find the repeating element in an array.

Examples :

Input :  arr[] = { 1, 2 , 3 , 4 , 4}
Output :  4

Input :  arr[] = { 1 , 1 , 2 , 3 , 4}
Output :  1

1- Check if the middle element is the repeating one.
2- If not then check if the middle element is at proper position if yes then start searching repeating element in right.
3- Otherwise the repeating one will be in left.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int FindRepeatingElement(int * arr, int left, int right)
{
    if (left > right)
        return -1;
    
    int mid = (left + right) / 2;
    if (mid > 0 && arr[mid] == arr[mid - 1])
        return mid;
    if (mid < right && arr[mid] == arr[mid + 1])
        return mid;
    
    return FindRepeatingElement(arr, left, mid - 1) + FindRepeatingElement(arr, mid + 1, right) + 1;
}

int main()
{
    int  arr[] = {1, 2, 3, 4, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n); // just make sure the input array is sorted before proceed

    int repeatingIndex = FindRepeatingElement(arr, 0, n - 1);
    if (repeatingIndex == -1)
    {
        std::cout << "No repeating element" << std::endl;
    }
    else
    {
        std::cout << arr[repeatingIndex] << std::endl;
    }
    

    return 0;
}