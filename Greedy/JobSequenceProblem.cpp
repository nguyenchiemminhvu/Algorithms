/*
https://www.geeksforgeeks.org/job-sequencing-problem/
https://dyclassroom.com/greedy-algorithm/job-sequencing-problem-with-deadline

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
#include <algorithm>
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

	void Print()
	{
		std::cout << "(" << _id << " " << _deadline << " " << _profit << ")" << std::endl;
	}
};

void SolveJobSequenceProblem(std::vector<Job> jobs, std::vector<int> &scheme)
{
	std::sort
	(
		jobs.begin(), 
		jobs.end(), 
		[](const Job &j1, const Job &j2)
		{
			return j1._profit > j2._profit;
		}
	);

	int dMax = 0;
	for (Job j : jobs)
		dMax = std::max(dMax, j._deadline);
	
	std::vector<int> slots(dMax + 1, -1);
	for (Job j : jobs)
	{
		int k = std::min(dMax, j._deadline);
		if (k >= 1)
		{
			if (slots[k] == -1)
			{
				slots[k] = j._id;
			}
			else
			{
				while (k >= 1 && slots[k] != -1)
				{
					k--;
				}

				if (k >= 1 && slots[k] == -1)
					slots[k] = j._id;
			}
		}
	}

	for (int i = 1; i <= dMax; i++)
		scheme.push_back(slots[i]);
}

int main()
{
	std::vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
	
	std::vector<int> scheme;
	SolveJobSequenceProblem(jobs, scheme);
	
	int totalProfit = 0;
	for (int id : scheme)
	{
		totalProfit += jobs[id - 1]._profit;
		std::cout << id << std::endl;
	}
	std::cout << "Maximum profit: " << totalProfit << std::endl;
	
	return 0;
}