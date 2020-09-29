/*
https://www.geeksforgeeks.org/maximum-path-sum-matrix/

Given a matrix of N * M. Find the maximum path sum in matrix. The maximum path is sum of all elements from first row to last row where you are allowed to move only down or diagonally to left or right. You can start from any element in first row.

Examples:

Input : mat[][] = 10 10  2  0 20  4
                   1  0  0 30  2  5
                   0 10  4  0  2  0
                   1  0  2 20  0  4
Output : 74
The maximum sum path is 20-30-4-20.

Input : mat[][] = 1 2 3
                  9 8 7
                  4 5 6
Output : 17
The maximum sum path is 3-8-6.
*/

#include <iostream>
#include <vector>
using namespace std;

int MaxPath(std::vector<std::vector<int>> board)
{
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (j == 0)
            {
                board[i][j] += std::max(board[i - 1][j], board[i - 1][j + 1]);
            }
            else if (j == board[i].size() - 1)
            {
                board[i][j] += std::max(board[i - 1][j], board[i - 1][j - 1]);
            }
            else if (j > 0 && j < board[i].size() - 1)
            {
                board[i][j] += std::max(board[i - 1][j - 1], std::max(board[i - 1][j], board[i - 1][j + 1]));
            }
        }
    }

    int res = 0;
    for (int j = 0; j < board[0].size(); j++)
    {
        res = std::max(res, board[board.size() - 1][j]);
    }
    return res;
}

int main()
{
    std::vector<std::vector<int>> m = { { 10, 10, 2, 0, 20, 4 }, 
                                        { 1, 0, 0, 30, 2, 5 }, 
                                        { 0, 10, 4, 0, 2, 0 }, 
                                        { 1, 0, 2, 20, 0, 4 } };

    std::cout << MaxPath(m) << std::endl;

    return 0;
}