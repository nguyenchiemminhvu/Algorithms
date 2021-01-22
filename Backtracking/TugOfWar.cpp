/*
https://www.geeksforgeeks.org/tug-of-war/

Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void TugOfWarPartition(int * arr, int n)
{
    
}

void TugOfWar(int * arr, int n)
{
    int sumAll = 0;
    for (int i = 0; i < n; i++)
        sumAll += arr[i];
    
    int minDiff = INT_MAX;


}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    TugOfWar(arr, n);

    return 0;
}