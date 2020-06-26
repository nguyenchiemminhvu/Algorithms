/*
Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak).
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. If there is no combination possible the print "Empty" (without quotes).

Examples:

Input : arr[] = 2, 4, 6, 8 
            x = 8
Output : [2, 2, 2, 2]
         [2, 2, 4]
         [2, 6]
         [4, 4]
         [8]

Approach:
1. Sort the array(non-decreasing).
2. First remove all the duplicates from array.
3. Then use recursion and backtracking to solve 
   the problem.
   (A) If at any time sub-problem sum == 0 then 
       add that array to the result (vector of 
       vectors).
   (B) Else if sum if negative then ignore that 
       sub-problem.
   (C) Else insert the present array in that 
       index to the current vector and call 
       the function with sum = sum-ar[index] and
       index = index, then pop that element from 
       current index (backtrack) and call the 
       function with sum = sum and index = index+1 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintAllCombination(const std::vector<std::vector<int>> &res)
{
    std::cout << "" << std::endl;
    for (std::vector<int> r : res)
    {
        for (int i = 0; i < r.size(); i++)
        {
            std::cout << r[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;
}

void SolveCombinationalSumProblem(
    const std::vector<int> &arr, 
    int sum, 
    int i,
    std::vector<int> &test, 
    std::vector<std::vector<int>> &res)
{
    if (sum < 0)
        return;
    
    if (sum == 0)
    {
        res.push_back(test);
        return;
    }
    
    while (i < arr.size() && sum - arr[i] >= 0)
    {
        test.push_back(arr[i]);

        SolveCombinationalSumProblem(arr, sum - arr[i], i, test, res);
        i++;
        
        test.pop_back();
    }
}

int main()
{
    std::vector<int> arr = { 2, 2, 4, 4, 6, 6, 7, 8 };
    int sum = 8;
    
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
    std::sort(arr.begin(), arr.end());

    std::vector<int> test;
    std::vector<std::vector<int>> res;
    SolveCombinationalSumProblem(arr, sum, 0, test, res);
    PrintAllCombination(res);

    return 0;
}
