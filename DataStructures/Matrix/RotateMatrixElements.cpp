/*
https://www.geeksforgeeks.org/rotate-matrix-elements/

Given a matrix, clockwise rotate elements in it.
Examples:

Input
1    2    3
4    5    6
7    8    9

Output:
4    1    2
7    5    3
8    9    6

For 4*4 matrix
Input:
1    2    3    4    
5    6    7    8
9    10   11   12
13   14   15   16

Output:
5    1    2    3
9    10   6    4
13   11   7    8
14   15   16   12

To rotate a ring, we need to do following.
    1) Move elements of top row.
    2) Move elements of last column.
    3) Move elements of bottom row.
    4) Move elements of first column.
Repeat above steps for inner ring while there is an inner ring.
*/

#include <iostream>
#include <vector>
using namespace std;

void RotateMatrix(std::vector<std::vector<int>> &m)
{
    if (!m.size() || !m[0].size())
        return;

    int row = m.size();
    int col = m[0].size();

    int r = 0, c = 0;
    int prev, cur;

    while (r < row && c < col)
    {
        if (r == row || c == col)
            break;
        
        prev = m[r + 1][c];

        for (int i = c; i < col; i++)
        {
            cur = m[r][i];
            m[r][i] = prev;
            prev = cur;
        }
        r++;

        for (int i = r; i < row; i++)
        {
            cur = m[i][col - 1];
            m[i][col - 1] = prev;
            prev = cur;
        }
        col--;

        if (r < row)
        {
            for (int i = col - 1; i >= c; i--)
            {
                cur = m[row - 1][i];
                m[row - 1][i] = prev;
                prev = cur;
            }
        }
        row--;

        if (c < col)
        {
            for (int i = row - 1; i >= r; i--)
            {
                cur = m[i][c];
                m[i][c] = prev;
                prev = cur;
            }
        }
        c++;
    }
}

int main()
{
    std::vector<std::vector<int>> m = { {1,  2,  3,  4}, 
                                        {5,  6,  7,  8}, 
                                        {9,  10, 11, 12}, 
                                        {13, 14, 15, 16} };

    RotateMatrix(m);

    for (std::vector<int> v : m)
    {
        for (int n : v)
        {
            std::cout << n << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}