/*
Given a partially filled 9×9 2D array ‘grid[9][9]’,
the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid
of size 3×3 contains exactly one instance of the digits from 1 to 9.

Example:

Input:
grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9
Explanation: Each row, column and 3*3 box of 
the output matrix contains unique numbers.

Input:    
grid = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
Output:
           3 1 6 5 7 8 4 9 2 
           5 2 9 1 3 4 7 6 8 
           4 8 7 6 2 9 5 3 1 
           2 6 3 4 1 5 9 8 7 
           9 7 4 8 6 3 1 2 5 
           8 5 1 7 9 2 6 4 3 
           1 3 8 9 4 7 2 5 6 
           6 9 2 3 5 1 8 7 4 
           7 4 5 2 8 6 3 1 9 
Explanation: Each row, column and 3*3 box of 
the output matrix contains unique numbers.

Approach:
Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells.
Before assigning a number, check whether it is safe to assign.
Check that the same number is not present in the current row, current column and current 3X3 subgrid.
After checking for safety, assign the number, and recursively check whether this assignment leads to a solution
or not. If the assignment doesn’t lead to a solution, then try the next number for the current empty cell.
And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.

Algorithm:

-   Create a function that checks after assigning the current index the grid becomes unsafe or not.
    Keep Hashmap for a row, column and boxes.
    If any number has a frequency greater than 1 in the hashMap return false else return true;
    hashMap can be avoided by using loops.

-   Create a recursive function which takes a grid.

-   Check for any unassigned location. If present then assign a number from 1 to 9,
    check if assigning the number to current index makes the grid unsafe or not,
    if safe then recursively call the function for all safe cases from 0 to 9.
    if any recursive call returns true, end the loop and return true.
    If no recursive call returns true then return false.

-   If there is no unassigned location then return true.
*/

#include <iostream>
#include <vector>
using namespace std;

#define N 9
#define UNASSIGNED 0

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

bool CheckRow(const std::vector<std::vector<int>> &board, int row)
{
    std::vector<int> freq(10, 0);
    for (int col = 0; col < 9; col++)
    {
        freq[board[row][col]]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (freq[i] > 1)
            return false;
    }

    return true;
}

bool CheckCol(const std::vector<std::vector<int>> &board, int col)
{
    std::vector<int> freq(10, 0);

    for (std::vector<int> row : board)
    {
        freq[row[col]]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (freq[i] > 1)
            return false;
    }

    return true;
}

bool CheckBlock(const std::vector<std::vector<int>> &board, int row, int col)
{
    int startX = (row / 3) * 3;
    int startY = (col / 3) * 3;

    cout << startX << " " << startY << endl;
    
    std::vector<int> freq(10, 0);
    for (int i = startX; i < startX + 3; i++)
    {
        for (int j = startY; j < startY + 3; j++)
        {
            freq[board[i][j]]++;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        if (freq[i] > 1)
            return false;
    }

    return true;
}

bool SolveSudokuProblem(std::vector<std::vector<int>> &board, int row, int col)
{
    if (row == N)
    {
        cout << "Done!" << endl;
        return true;
    }
    
    if (board[row][col] == 0)
    {
        for (int value = 1; value <= 9; value++)
        {
            board[row][col] = value;
            if (CheckRow(board, row) && CheckCol(board, col) && CheckBlock(board, row, col))
            {
                int nextRow = row;
                int nextCol = col + 1;
                if (nextCol == N)
                {
                    nextRow++;
                    nextCol = 0;
                }

                if (SolveSudokuProblem(board, nextRow, nextCol))
                    return true;
            }
            board[row][col] = 0;
        }
    }
    else
    {
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == N)
        {
            nextRow++;
            nextCol = 0;
        }

        if (SolveSudokuProblem(board, nextRow, nextCol))
            return true;
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> board = 
    {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };

    if (SolveSudokuProblem(board, 0, 0))
        PrintBoard(board);

    return 0;
}