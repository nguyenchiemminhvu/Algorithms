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
    int m = m.size();
    int n = m[0].size();

    
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