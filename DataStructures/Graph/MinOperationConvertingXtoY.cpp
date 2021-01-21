/*
https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/

Given a initial number x and two operations which are given below:

(1) Multiply number by 2.
(2) Subtract 1 from the number.

The task is to find out minimum number of operation required to convert number x into y using only above two operations. We can apply these operations any number of times.

Constraints:
1 <= x, y <= 10000

Example:

Input : x = 4, y = 7
Output : 2
We can transform x into y using following
two operations.
1. 4*2  = 8
2. 8-1  = 7

Input  : x = 2, y = 5
Output : 4
We can transform x into y using following
four operations.
1. 2*2  = 4
2. 4-1   = 3
3. 3*2  = 6
4. 6-1   = 5
Answer = 4
Note that other sequences of two operations 
would take more operations.

The idea is to use BFS for this. We run a BFS and create nodes by multiplying with 2 and subtracting by 1, thus we can obtain all possible numbers reachable from starting number.
Important Points :
1) When we subtract 1 from a number and if it becomes < 0 i.e. Negative then there is no reason to create next node from it (As per input constraints, numbers x and y are positive).
2) Also, if we have already created a number then there is no reason to create it again. i.e. we maintain a visited array.
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int MinOperations(int from, int to)
{
    using NODE = std::pair<int, int>;

    std::map<int, bool> visited;

    std::queue<NODE> Q;
    Q.push( {from, 0} );
    visited[from] = true;

    while (!Q.empty())
    {
        NODE u = Q.front();
        Q.pop();

        if (u.first == to)
            return u.second;
        
        if (u.first - 1 == to || u.first * 2 == to)
            return u.second + 1;
        
        if (!visited[u.first * 2])
            Q.push( { u.first * 2, u.second + 1 } );
        
        if (!visited[u.first - 1] && u.first - 1 >= 0)
            Q.push( { u.first - 1, u.second + 1 } );
    }

    return -1;
}

int main()
{
    int from = 2, to = 5;
    std::cout << MinOperations(from, to) << std::endl;

    return 0;
}