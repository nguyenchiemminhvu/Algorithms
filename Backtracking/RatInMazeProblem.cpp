/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., 
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
A rat starts from source and has to reach the destination. 
The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.
Note that this is a simple version of the typical Maze problem. 
For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with a limited number of moves.

Approach:
Form a recursive function, which will follow a path and check if the path reaches the destination or not.
If the path does not reach the destination then backtrack and try other paths.

Algorithm:
- Create a solution matrix, initially filled with 0’s.
- Create a recursive funtion, which takes initial matrix, output matrix and position of rat (i, j).
- if the position is out of the matrix or the position is not valid then return.
- Mark the position output[i][j] as 1 and check if the current position is destination or not. If destination is reached print the output matrix and return.
- Recursively call for position (i+1, j) and (i, j+1).
- Unmark position (i, j), i.e output[i][j] = 0.
*/

#include <iostream>
#include <vector>
using namespace std;

int xMove[8] = { 0, 1 }; 
int yMove[8] = { 1, 0 };

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

bool IsSafeMove(const std::vector<std::vector<int>> &board, int x, int y)
{
    return x >= 0 && x < board.size() && y >= 0 && y < board[x].size();
}

bool SolveRatInMazeProblem(
    const std::vector<std::vector<int>> &board,
    std::vector<std::vector<int>> &solution,
    int x,
    int y)
{
    PrintBoard(solution);
    if (x == board.size() - 1 && y == board[x].size() - 1)
        return true;
    
    for (int i = 0; i < 2; i++)
    {
        int nextX = x + xMove[i];
        int nextY = y + xMove[i];

        if (IsSafeMove(board, nextX, nextY) && board[nextX][nextY] == 1 && solution[nextX][nextY] == 0)
        {
            solution[nextX][nextY] = 1;
            if (SolveRatInMazeProblem(board, solution, nextX, nextY))
                return true;
            solution[nextX][nextY] = 0;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> board =
    {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 1 },
    };

    std::vector<std::vector<int>> solution(board.size(), std::vector<int>(board[0].size(), 0));
    solution[0][0] = 1;

    if (SolveRatInMazeProblem(board, solution, 0, 0))
        PrintBoard(solution);

    return 0;
}