#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define N 4

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
        PrintBoard(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < board[row].size(); col++)
    {
        if (!cCol[col] && !cDiag1[row - col] && !cDiag2[row + col])
        {
            board[row][col] = 1;
            cCol[col] = cDiag1[row - col] = cDiag2[row + col] = 1;
            
            res |= SolveNQueenProblem(board, cCol, cDiag1, cDiag2, row + 1);

            cCol[col] = cDiag1[row - col] = cDiag2[row + col] = 0;
            board[row][col] = 0;
        }
    }

    return res;
}

int main()
{
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    
    std::map<int, int> cCol;
    std::map<int, int> cDiag1;
    std::map<int, int> cDiag2;
    SolveNQueenProblem(board, cCol, cDiag1, cDiag2, 0);

    return 0;
}