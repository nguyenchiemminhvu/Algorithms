/*
https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Example:

Example 1 : Consider the following 3 activities sorted by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities.
The maximum set of activities that can be executed is {0, 2}
[ These are indexes in start[] and finish[] ]

Example 2 : Consider the following 6 activities sorted by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities.
The maximum set of activities that can be executed is {0, 1, 3, 4}
[ These are indexes in start[] and finish[] ]


*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Activity
{
    int _start;
    int _finish;

    Activity(int s = 0, int f = 0)
        : _start(s), _finish(f)
    {

    }
};

void SolveActivitySelectionProblem(std::vector<Activity> activities, std::vector<int> &selection)
{
    selection.clear();

    std::sort
    (
        activities.begin(),
        activities.end(),
        [](const Activity &a, const Activity &b)
        {
            return a._finish < b._finish;
        }
    );

    int cur = 0;
    selection.push_back(cur);

    for (int next = 1; next < activities.size(); next++)
    {
        if (activities[next]._start >= activities[cur]._finish)
        {
            selection.push_back(next);
            cur = next;
        }
    }    
}

int main()
{
    std::vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    std::vector<int> selection;
    SolveActivitySelectionProblem(activities, selection);
    for (int i = 0; i < selection.size(); i++)
    {
        int cur = selection[i];
        std::cout << activities[cur]._start << " " << activities[cur]._finish << std::endl;
    }

    return 0;
}