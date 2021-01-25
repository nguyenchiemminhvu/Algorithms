/*
https://www.geeksforgeeks.org/tug-of-war/

Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void TugOfWarPartition(
    int * arr, 
    int n, 
    std::vector<bool> &cur_elements, 
    std::vector<bool> &solution,
    int sum,
    int &minDiff,
    int num_selected,
    int cur_sum,
    int cur_pos)
{
    if (cur_pos == n)
        return;
    
    if ((n / 2 - num_selected) > (n - cur_pos))
        return;
    
    // consider the case when current element is not included
    TugOfWarPartition(arr, n, cur_elements, solution, sum, minDiff, num_selected, cur_sum, cur_pos + 1);

    num_selected++;
    cur_sum += arr[cur_pos];
    cur_elements[cur_pos] = true;

    if (num_selected == n / 2)
    {
        // check if the formed solution is better than the best solution so far
        if (abs(sum / 2 - cur_sum) < minDiff)
        {
            minDiff = sum / 2 - cur_sum;
            for (int i = 0; i < n; i++)
                solution[i] = cur_elements[i];
        }
    }
    else
    {
        // consider the case when current element is included
        TugOfWarPartition(arr, n, cur_elements, solution, sum, minDiff, num_selected, cur_sum, cur_pos + 1);
    }

    cur_elements[cur_pos] = false;
}

void TugOfWar(int * arr, int n)
{
    int sumAll = 0;
    for (int i = 0; i < n; i++)
        sumAll += arr[i];
    
    int minDiff = INT_MAX;

    std::vector<bool> cur_elements(n, false);
    std::vector<bool> solution(n, false);

    TugOfWarPartition(arr, n, cur_elements, solution, sumAll, minDiff, 0, 0, 0);

    for (int i = 0; i < n; i++)
    {
        if (solution[i])
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (!solution[i])
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    TugOfWar(arr, n);

    return 0;
}