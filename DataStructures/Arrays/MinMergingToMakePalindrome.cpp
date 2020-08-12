/*
https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

Given an array of positive integers. We need to make the given array a ‘Palindrome’. Only allowed operation on array is merge. Merging two adjacent elements means replacing them with their sum. The task is to find minimum number of merge operations required to make given array a ‘Palindrome’.

To make an array a palindromic we can simply apply merging operations n-1 times where n is the size of array (Note a single element array is alway palindrome similar to single character string). In that case, size of array will be reduced to 1. But in this problem we are asked to do it in minimum number of operations.

Example :

Input : arr[] = {15, 4, 15}
Output : 0
Array is already a palindrome. So we
do not need any merge operation.

Input : arr[] = {1, 4, 5, 1}
Output : 1
We can make given array palindrome with
minimum one merging (merging 4 and 5 to
make 9)

Input : arr[] = {11, 14, 15, 99}
Output : 3
We need to merge all elements to make
a palindrome.
*/

#include <iostream>
using namespace std;

int MinMergingToMakePalindrome(int * arr, int n)
{
    int res = 0;

    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left] == arr[right])
        {
            left++;
            right--;
        }
        else
        {
            if (arr[left] < arr[right])
            {
                left++;
                arr[left] += arr[left - 1];
                res++;
            }
            else if (arr[right > arr[left]])
            {
                right--;
                arr[right] += arr[right + 1];
                res++;
            }
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 4, 5, 9, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << MinMergingToMakePalindrome(arr, n) << std::endl;

    return 0;
}