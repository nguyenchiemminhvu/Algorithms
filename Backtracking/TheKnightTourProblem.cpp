/*
The knight is placed on the first block of an empty board and, 
moving according to the rules of chess, must visit each square exactly once.

Naive Algorithm for Knight’s tour
=================================

The Naive Algorithm is to generate all tours one by one and check if the generated tour satisfies the constraints.

while there are untried tours
{ 
   generate the next tour 
   if this tour covers all squares 
   { 
      print this path;
   }
}
Backtracking works in an incremental way to attack problems. Typically, we start from an empty solution vector and one by one add items (Meaning of item varies from problem to problem. In context of Knight’s tour problem, an item is a Knight’s move). When we add an item, we check if adding the current item violates the problem constraint, if it does then we remove the item and try other alternatives. If none of the alternatives work out then we go to previous stage and remove the item added in the previous stage. If we reach the initial stage back then we say that no solution exists. If adding an item doesn’t violate constraints then we recursively add items one by one. If the solution vector becomes complete then we print the solution.

Backtracking Algorithm for Knight’s tour
========================================

Following is the Backtracking algorithm for Knight’s tour problem.

If all squares are visited 
    print the solution
Else
   a) Add one of the next moves to solution vector and recursively 
   check if this move leads to a solution. (A Knight can make maximum 
   eight moves. We choose one of the 8 moves in this step).
   b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other 
   alternative moves.
   c) If none of the alternatives work then return false (Returning false 
   will remove the previously added item in recursion and if false is 
   returned by the initial call of recursion then "no solution exists" )
*/

#include <iostream>
#include <vector>
using namespace std;

#define N 8

int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

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
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool SolveKnightTourProblem(std::vector<std::vector<int>> &board, int fromX, int fromY, int total = 1)
{
    if (total == N * N)
    {
        std::cout << "DONE!" << endl;
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int nextX = fromX + xMove[i];
        int nextY = fromY + yMove[i];

        if (IsSafeMove(board, nextX, nextY) && board[nextX][nextY] == -1)
        {
            board[nextX][nextY] = total;
            if (SolveKnightTourProblem(board, nextX, nextY, total + 1))
                return true;
            board[nextX][nextY] = -1;
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));
    board[0][0] = 0;

    if (SolveKnightTourProblem(board, 0, 0))
        PrintBoard(board);

    return 0;
}