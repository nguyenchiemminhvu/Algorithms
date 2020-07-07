/*
https://www.geeksforgeeks.org/find-number-diagonals-n-sided-convex-polygon/

Examples :

Input : 5
Output : 5

Solution :

Since for an n-sided convex polygon, from each vertex,
we can draw n-3 diagonals leaving two adjacent vertices and itself.
Following this way for n-vertices, there will be n*(n-3) diagonals
but then we will be calculating each diagonal twice so total number of diagonals become n*(n-3)/2
*/

#include <iostream>
using namespace std;

int NumberOfDiagonalsInPolygon(int n)
{
    return n * (n - 3) / 2;
}

int main()
{
    int n = 5;
    std::cout << NumberOfDiagonalsInPolygon(n) << std::endl;
    
    return 0;
}