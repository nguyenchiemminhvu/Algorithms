/*
https://www.techiedelight.com/minimum-sum-partition-problem/

Given a set of postitive integers S, partition the set S into two subsets S1 and S2, such that the different between the sum of elements in S1 and the sum of elements in S2 is minimized
*/

#include <iostream>
#include <algorithm>
using namespace std;

int MinDiffOfTwoPartition(int * arr, int i, int s1, int s2)
{
    if (i < 0)
        return abs(s1 - s2);
    
    int in = MinDiffOfTwoPartition(arr, i - 1, s1 + arr[i], s2);
    int ex = MinDiffOfTwoPartition(arr, i - 1, s1, s2 + arr[i]);
    return std::min(in, ex);
}

int main()
{
    int arr[] = { 10, 20, 15, 5, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << MinDiffOfTwoPartition(arr, n - 1, 0, 0) << std::endl;

    return 0;
}