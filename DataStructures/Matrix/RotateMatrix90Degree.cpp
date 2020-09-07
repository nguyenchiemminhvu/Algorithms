/*
https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/

Given a square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.

Examples:

Input:
 1  2  3
 4  5  6
 7  8  9
Output:
 3  6  9 
 2  5  8 
 1  4  7 
Rotated the input matrix by
90 degrees in anti-clockwise direction.

Input:
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15 16 
Output:
 4  8 12 16 
 3  7 11 15 
 2  6 10 14 
 1  5  9 13
Rotated the input matrix by
90 degrees in anti-clockwise direction.

Algorithm:

To solve the given problem there are two tasks. 1st is finding the transpose and second is reversing the columns without using extra space
A transpose of a matrix is when the matrix is flipped over its diagonal, i.e the row index of an element becomes the column index and vice versa. So to find the transpose interchange the elements at position (i, j) with (j, i). Run two loops, the outer loop from 0 to row count and inner loop from 0 to index of the outer loop.
To reverse the column of the transposed matrix, run two nested loops, the outer loop from 0 to column count and inner loop from 0 to row count/2, interchange elements at (i, j) with (i, row[count-1-j]), where i and j are indices of inner and outer loop respectively.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ReverseRows(std::vector<std::vector<int>> &m)
{
    int up = 0, down = m.size() - 1;
    while (up <= down)
    {
        std::swap(m[up], m[down]);

        up++;
        down--;
    }
}

void ReverseColumns(std::vector<std::vector<int>> &m)
{
    for (std::vector<int> &v : m)
    {
        std::reverse(v.begin(), v.end());
    }
}

void DoTranspose(std::vector<std::vector<int>> &m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (i < j)
                std::swap(m[i][j], m[j][i]);
        }
    }
}

void RotateAntiClockwise(std::vector<std::vector<int>> &m)
{
    DoTranspose(m);
    ReverseRows(m);
}

void RotateClockwise(std::vector<std::vector<int>> &m)
{
    DoTranspose(m);
    ReverseColumns(m);
}

int main()
{
    std::vector<std::vector<int>> m = { { 1, 2, 3, 4 }, 
                                        { 5, 6, 7, 8 }, 
                                        { 9, 10, 11, 12 }, 
                                        { 13, 14, 15, 16 } };

    RotateAntiClockwise(m);
    
    for (std::vector<int> v : m)
    {
        for (int n : v)
        {
            std::cout << n << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    RotateClockwise(m);

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