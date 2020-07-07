/*
https://www.geeksforgeeks.org/pizza-cut-problem-circle-division-lines/

Given number of cuts, find the maximum number of possible pieces.

Examples:

Input  : 2
Output : 4

Input  : 3
Output : 7

Let f(n) denote the maximum number of pieces
that can be obtained by making n cuts.
Trivially,
f(0) = 1                                 
As there'd be only 1 piece without any cut.

Similarly,
f(1) = 2

Proceeding in similar fashion we can deduce 
the recursive nature of the function.
The function can be represented recursively as :
f(n) = n + f(n-1)

Hence a simple solution based on the above 
formula can run in O(n). 
We can optimize above formula.

We now know ,
f(n) = n + f(n-1) 

Expanding f(n-1) and so on we have ,
f(n) = n + n-1 + n-2 + ...... + 1 + f(0)

which gives,
f(n) = (n*(n+1))/2 + 1
*/

#include <iostream>
using namespace std;

int SolvePizzaCutProblem(int n)
{
    return 1 + n * (n + 1) / 2;
}

int main()
{
    std::cout << SolvePizzaCutProblem(3) << std::endl;
    return 0;
}