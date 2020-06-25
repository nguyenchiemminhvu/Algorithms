/*
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
For example, following is the output matrix for above 4 queen solution.

    { 0,  1,  0,  0}
    { 0,  0,  0,  1}
    { 1,  0,  0,  0}
    { 0,  0,  1,  0}

The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and return false.

1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column. 
   Do following for every tried row.
    a) If the queen can be placed safely in this row 
        then mark this [row, column] as part of the 
        solution and recursively check if placing
        queen here leads to a solution.
    b) If placing the queen in [row, column] leads to
        a solution then return true.
    c) If placing queen doesn't lead to a solution then
        unmark this [row, column] (Backtrack) and go to 
        step (a) to try other rows.
3) If all rows have been tried and nothing worked,
    return false to trigger backtracking.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define N 8

void PrintBoard(const std::vector<std::vector<int>> &board)
{
    std::cout << "" << std::endl;
    for (std::vector<int> row : board)
    {
        for (int i = 0; i < row.size(); i++)
        {
            std::cout << row[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;
}

bool SolveNQueenProblem(
    std::vector<std::vector<int>> &board, 
    std::map<int, int> cCol, 
    std::map<int, int> cDiag1, 
    std::map<int, int> cDiag2,
    int row)
{
    if (row == board.size())
    {
        return true;
    }

    for (int col = 0; col < board[row].size(); col++)
    {
        if (!cCol[col] && !cDiag1[row - col] && !cDiag2[row + col])
        {
            board[row][col] = 1;
            cCol[col] = cDiag1[row - col] = cDiag2[row + col] = 1;
            
            if (SolveNQueenProblem(board, cCol, cDiag1, cDiag2, row + 1))
                return true;

            cCol[col] = cDiag1[row - col] = cDiag2[row + col] = 0;
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    
    std::map<int, int> cCol;
    std::map<int, int> cDiag1;
    std::map<int, int> cDiag2;
    if (SolveNQueenProblem(board, cCol, cDiag1, cDiag2, 0))
    {
        PrintBoard(board);
    }

    return 0;
}