/*
Given a set of positive integers, find all its subsets.
Examples:

Input: array = {1, 2, 3}
Output: // this space denotes null element. 
         1
         1 2
         1 2 3
         1 3
         2
         2 3
         3
Explanation: These are all the subsets that 
can be formed using the array.

Input: 1 2
Output: 
         1 
         2
         1 2
Explanation: These are all the subsets that 
can be formed using the array.

Approach: The idea is simple, that if there are n number of elements inside an array, there are two choices for every element. Either include that element in the subset or do not include it.
Using the above idea form a recursive solution to the problem.

Algorithm:

- Create a recursive function that takes the following parameters, input array, the current index, the output array or current subset, if all the subsets needs to be stored then a vector of array is needed, if the subsets need to be printed only then this space can be ignored.
- if the current index is equal to the size of the array, then print the subset or ouput array or insert the output array into the vector of arrays (or vectors) and return.
- There are exactly two choices for very index.
- Ignore the current element and call the recursive function with the current subset and next index, i.e i + 1.
- Insert the current element in the subset and call the recursive function with the current subset and next index, i.e i + 1.
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

void FindAllSubsets(
    const std::vector<int> &arr,
    int idx,
    std::vector<int> &test,
    std::vector<std::vector<int>> &res)
{
    res.push_back(test);
    
    for (int i = idx; i < arr.size(); i++)
    {
        test.push_back(arr[i]);
        FindAllSubsets(arr, i + 1, test, res);
        test.pop_back();
    }
}

int main()
{
    std::vector<int> arr = { 1, 2, 3 };

    std::vector<int> test;
    std::vector<std::vector<int>> res;
    FindAllSubsets(arr, 0, test, res);
    PrintSubsets(res);

    return 0;
}