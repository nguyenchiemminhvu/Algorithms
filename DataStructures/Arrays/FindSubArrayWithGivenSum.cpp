/*
https://www.geeksforgeeks.org/find-subarray-with-given-sum/

Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number.
Examples :

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Ouptut: Sum found between indexes 1 and 4
Sum of elements between indices
1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum

Algorithm:

Create three variables, l=0, sum = 0
Traverse the array from start to end.
Update the variable sum by adding current element, sum = sum + array[i]
If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
If the sum is equal to given sum, print the subarray and break the loop.
*/

#include <iostream>
#include <limits.h>
using namespace std;

bool SubArrayWithGivenSum(int * arr, int n, int sum, std::pair<int, int> &subarray)
{
    int CurSum = arr[0], start = 0;

    for (int i = 1; i < n; i++)
    {
        while (CurSum > sum && start < i)
        {
            CurSum -= arr[start];
            start++;
        }

        if (CurSum == sum)
        {
            subarray.first = start;
            subarray.second = i - 1;
            return true;
        }

        CurSum += arr[i];
    }

    return false;
}

int main()
{
    int arr[] = { 1, 4, 45, 6, 10, 19 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 51; 

    std::pair<int, int> subarray;
    if (SubArrayWithGivenSum(arr, n, sum, subarray))
    {
        std::cout << subarray.first << " " << subarray.second << std::endl;
    }
    else
    {
        std::cout << "No possible subarray" << std::endl;
    }

    return 0;
}