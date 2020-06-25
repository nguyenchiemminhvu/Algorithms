/*
Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K.
We are considering the set contains non-negative values.
It is assumed that the input set is unique (no duplicates are presented).
*/

#include <iostream>
#include <vector>
using namespace std;

void PrintSubsets(const std::vector<std::vector<int>> &subsets)
{
    std::cout << "" << std::endl;
    for (std::vector<int> subset : subsets)
    {
        for (int i = 0; i < subset.size(); i++)
        {
            std::cout << subset[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;
}

void SolveSubsetSumProblem(int * arr, int n, int sum, int curIdx, std::vector<std::vector<int>> &res, std::vector<int> &test)
{
    if (sum == 0)
    {
        res.push_back(test);
        return;
    }

    for (int i = curIdx; i < n; i++)
    {
        if (arr[i] <= sum)
        {
            test.push_back(arr[i]);
            SolveSubsetSumProblem(arr, n, sum - arr[i], i + 1, res, test);
            test.pop_back();
        }
    }
}

int main()
{
    int arr[] = { 10, 7, 5, 18, 12, 20, 15 };
    int n = sizeof(arr) / sizeof(int);
    int sum = 35;

    std::vector<std::vector<int>> res;
    std::vector<int> subset;
    SolveSubsetSumProblem(arr, n, sum, 0, res, subset);
    PrintSubsets(res);

    return 0;
}