/*
https://www.geeksforgeeks.org/program-for-scalar-multiplication-of-a-matrix/
https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
https://www.geeksforgeeks.org/matrix-multiplication-recursive/

Given a matrix and a scalar element k, our task is to find out the scalar product of that matrix.

Examples:

Input : mat[][] = {{2, 3}
                   {5, 4}}
        k = 5
Output : 10 15 
         25 20 
We multiply 5 with every element.

Input : 1 2 3 
        4 5 6
        7 8 9
        k = 4
Output :  4 8  12
          16 20 24
          28 32 36 

===================================

Given two matrices, the task to multiply them. Matrices can either be square or rectangular.

Examples:

Input : mat1[][] = {{1, 2}, 
                   {3, 4}}
        mat2[][] = {{1, 1}, 
                    {1, 1}}
Output : {{3, 3}, 
          {7, 7}}
Input : mat1[][] = {{2, 4}, 
                    {3, 4}}
        mat2[][] = {{1, 2}, 
                    {1, 3}}       
Output : {{6, 16}, 
          {7, 18}}
*/

#include <iostream>
#include <vector>
using namespace std;

void MultiplyToScalar(std::vector<std::vector<int>> &m, int scalar)
{
    for (std::vector<int> & r : m)
    {
        for (int & c : r)
        {
            c *= scalar;
        }
    }
}

void MultiplyToMatrix(
    std::vector<std::vector<int>> m1, 
    std::vector<std::vector<int>> m2, 
    std::vector<std::vector<int>> &res)
{
    for (int i = 0; i < m1.size(); i++)
    {
        for (int j = 0; j < m1[0].size(); j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m2.size(); k++)
            {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> m = { { 1, 2, 3 }, 
                                        { 4, 5, 6 }, 
                                        { 7, 8, 9 } };
    
    int scalar = 4;
    MultiplyToScalar(m, scalar);

    for (std::vector<int> r : m)
    {
        for (int c : r)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::vector<std::vector<int>> m1 = {{1, 1, 1, 1}, 
                                        {2, 2, 2, 2}, 
                                        {3, 3, 3, 3}, 
                                        {4, 4, 4, 4}};
    std::vector<std::vector<int>> m2 = {{1, 1, 1, 1}, 
                                        {2, 2, 2, 2}, 
                                        {3, 3, 3, 3}, 
                                        {4, 4, 4, 4}};
    std::vector<std::vector<int>> mm(m1.size(), std::vector<int>(m2[0].size()));

    MultiplyToMatrix(m1, m2, mm);
    for (std::vector<int> r : mm)
    {
        for (int c : r)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}