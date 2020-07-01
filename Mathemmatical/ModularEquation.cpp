/*
https://www.geeksforgeeks.org/given-two-numbers-b-find-x-x-b/

Given two numbers a and b find all x such that a % x = b .

Examples:

Input : a = 21, b = 5
Output : 2
The answers of the Modular Equation are
8 and 16 since 21 % 8 = 21 % 16 = 5

Here 3 cases arises :

If ( a < b ) then there will be no answer .

If ( a = b ) then all the numbers greater than a are the answer so there will be infinite solutions possible.

If ( a > b ) Suppose x is an answer to our equation. 
Then x divides (a – b). 
Also since a % x = b then b < x. 
These conditions are necessary and sufficient as well. 
So the answer is number of divisors of a – b which are strictly greater than b 
which can be solved in O(sqrt( a-b )). 
Here only one case arises which we have to deal separately when (a-b) is perfect square 
then we will add its square root two times so we have to subtract one times, 
if this case arises.
*/

#include <iostream>
#include <cmath>
using namespace std;

int ModularEquation(int a, int b)
{
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    
    int count = 0;
    int n = a - b;
    int y = sqrt(a - b);
    for (int i = 1; i <= y; i++)
    {
        if (n % i == 0)
        {
            if (n / i > b)
                count++;
            if (i > b)
                count++;
        }
    }

    if (y * y == n && y > b)
        count--;

    return count;
}

int main()
{
    int a = 21, b = 5; 
    
    int x = ModularEquation(a, b);
    if (x == -1)
    {
        std::cout << "No solution" << std::endl;
    }
    else if (x == 0)
    {
        std::cout << "Infinite number of solution" << std::endl;
    }
    else
    {
        std::cout << x << " solutions" << std::endl;
    }
    

    return 0;
}