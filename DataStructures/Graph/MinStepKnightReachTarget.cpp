/*
https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out the minimum steps a Knight will take to reach the target position.

Approach:
This problem can be seen as shortest path in unweighted graph. Therefore we use BFS to solve this problem. We try all 8 possible positions where a Knight can reach from its position. If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.

Below code implements BFS for searching through cells, where each cell contains its coordinate and distance from starting node. In worst case, below code visits all cells of board, making worst-case time complexity as O(N^2)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

using POS = std::pair<int, int>;

struct CELL
{
    POS p;
    int dist;
};

bool isValidPos(int N, POS p)
{
    return p.first >= 1 && p.first <= N && p.second >= 1 && p.second <= N;
}

int countMinStepKnightReachTarget(int N, POS knight, POS target)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

    std::map<POS, int> visited;

    std::queue<CELL> Q;
    Q.push({ knight, 0 });
    visited[knight] = 1;

    while (!Q.empty())
    {
        CELL u = Q.front();
        Q.pop();

        if (u.p == target)
            return u.dist;
        
        for (int i = 0; i < 8; i++)
        {
            int vx = u.p.first + dx[i];
            int vy = u.p.second + dy[i];
            if (isValidPos(N, {vx, vy}) && !visited[{vx, vy}])
            {
                visited[{vx, vy}] = 1;
                Q.push( { {vx, vy}, u.dist + 1 } );
            }
        }
    }

    return -1;
}

int main()
{
    int N = 8;
    POS knight = {4, 5}; 
    POS target = {1, 1};

    std::cout << countMinStepKnightReachTarget(N, knight, target);

    return 0;
}