/*
https://www.geeksforgeeks.org/number-rectangles-nm-grid/

We are given a N*M grid, print the number of rectangles in it.

Examples:

Input  : N = 2, M = 2
Output : 9
There are 4 rectangles of size 1 x 1.
There are 2 rectangles of size 1 x 2
There are 2 rectangles of size 2 x 1
There is one rectangle of size 2 x 2.

Input  : N = 5, M = 4
Output : 150

Input :  N = 4, M = 3
Output: 60
*/

#include <iostream>
using namespace std;

int rectCount(int m, int n) 
{ 
    return (m * n * (n + 1) * (m + 1)) / 4; 
} 

int main()
{
    int m = 5, n = 4;
    std::cout << rectCount(m, n) << std::endl;

    return 0;
}