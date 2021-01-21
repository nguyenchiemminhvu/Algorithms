/*
https://www.geeksforgeeks.org/stepping-numbers/

Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m]. A number is called stepping number if all adjacent digits have an absolute difference of 1. 321 is a Stepping Number while 421 is not.
Examples : 
 

Input : n = 0, m = 21
Output : 0 1 2 3 4 5 6 7 8 9 10 12 21

Input : n = 10, m = 15
Output : 10, 12
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

void BFS_Stepping(int from, int to, int num)
{
    std::queue<int> Q;
    Q.push(num);

    while (!Q.empty())
    {
        int step = Q.front();
        Q.pop();

        if (step >= from && step <= to)
            std::cout << step << " ";
        
        if (num == 0 || step > to)
            continue;
        
        int lastDigit = step % 10;
        int stepA = step * 10 + lastDigit + 1;
        int stepB = step * 10 + lastDigit - 1;

        if (lastDigit == 0)
        {
            Q.push(stepA);
        }
        else if (lastDigit == 9)
        {
            Q.push(stepB);
        }
        else
        {
            Q.push(stepA);
            Q.push(stepB);
        }
        
    }
}

void ListSteppingNumbers(int from, int to)
{
    for (int i = 0; i <= 9; i++)
    {
        BFS_Stepping(from, to, i);
    }
}

int main()
{
    int from = 0, to = 21;
    ListSteppingNumbers(from, to);

    return 0;
}