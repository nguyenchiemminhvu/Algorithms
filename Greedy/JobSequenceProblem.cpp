/*
https://www.geeksforgeeks.org/job-sequencing-problem/

Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

Examples:

Input: Four Jobs with following 
deadlines and profits
JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum 
profit sequence of jobs
        c, a   


Input:  Five Jobs with following
deadlines and profits
JobID   Deadline  Profit
  a       2        100
  b       1        19
  c       2        27
  d       1        25
  e       3        15
Output: Following is maximum 
profit sequence of jobs
        c, a, e

1) Sort all jobs in decreasing order of profit.
2) Iterate on jobs in decreasing order of profit.For each job , do the following :
a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in
this slot and mark this slot filled.
b)If no such i exists, then ignore the job.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Job
{
    int _id;
    int _deadline;
    int _profit;

    Job(int id = 0, int d = 0, int p = 0)
        : _id(id), _deadline(d), _profit(p)
    {

    }
};

void SolveJobSequenceProblem(std::vector<Job> jobs, std::vector<Job> &scheme)
{

}

int main()
{
    std::vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};

    std::vector<Job> scheme;
    SolveJobSequenceProblem(jobs, scheme);

    for (Job j : scheme)
    {
        std::cout << j._id << " " << j._deadline << " " << j._profit << std::endl;
    }

    return 0;
}