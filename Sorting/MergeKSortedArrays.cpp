/*
https://www.geeksforgeeks.org/merge-k-sorted-arrays/

Given k sorted arrays of size n each, merge them and print the sorted output.
Example: 
 

Input: 
k = 3, n = 4 
arr[][] = { {1, 3, 5, 7}, 
{2, 4, 6, 8}, 
{0, 9, 10, 11}} ;
Output: 0 1 2 3 4 5 6 7 8 9 10 11 
Explanation: The output array is a sorted array that contains all the elements of the input matrix. 
Input: 
k = 3, n = 4 
arr[][] = { {1, 5, 6, 8}, 
{2, 4, 10, 12}, 
{3, 7, 9, 11}, 
{13, 14, 15, 16}} ;
Output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
Explanation: The output array is a sorted array that contains all the elements of the input matrix. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void MergeKSortedArrays(const std::vector<std::vector<int>> &kArrays, std::vector<int> &out)
{
    using PIP = std::pair<int, std::pair<int, int>>;
    std::priority_queue<PIP, std::vector<PIP>, std::greater<PIP>> PQ;
    for (int i = 0; i < kArrays.size(); i++)
    {
        PQ.push( { kArrays[i][0], { i, 0 } } );
    }

    int io = 0;
    while (!PQ.empty())
    {
        PIP cur = PQ.top();
        PQ.pop();

        out[io++] = cur.first;

        int i = cur.second.first;
        int j = cur.second.second;
        if (j + 1 < kArrays[i].size())
        {
            PQ.push( { kArrays[i][j + 1], { i, j + 1 } } );
        }
    }
}

int main()
{
    std::vector<std::vector<int>> kArrays = {{2, 6, 12},
                                            {1, 9, 20, 1000},
                                            {23, 34, 90, 2000, 3000}};

    std::vector<int> merged(kArrays.size() * kArrays[0].size());
    MergeKSortedArrays(kArrays, merged);
    for (int n : merged)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}