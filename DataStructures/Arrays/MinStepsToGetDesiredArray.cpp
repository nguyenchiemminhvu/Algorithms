/*
https://www.geeksforgeeks.org/count-minimum-steps-get-given-desired-array/

Consider an array with n elements and value of all the elements is zero. We can perform following operations on the array.

Incremental operations:Choose 1 element from the array and increment its value by 1.
Doubling operation: Double the values of all the elements of array.
We are given desired array target[] containing n elements. Compute and return the smallest possible number of the operations needed to change the array from all zeros to desired array.

Examples:

Input: target[] = {2, 3}
Output: 4
To get the target array from {0, 0}, we 
first increment both elements by 1 (2 
operations), then double the array (1 
operation). Finally increment second
element (1 more operation)

Input: target[] = {2, 1}
Output: 3
One of the optimal solution is to apply the 
incremental operation 2 times to first and 
once on second element.

Input: target[] = {16, 16, 16}
Output: 7
The output solution looks as follows. First 
apply an incremental operation to each element. 
Then apply the doubling operation four times. 
Total number of operations is 3+4 = 7
*/

#include <iostream>
using namespace std;

int MinStepsToGetDesiredArray(int * target, int n)
{
    int res = 0;

    while (true)
    {
        int countZero = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            if (target[i] == 0)
                countZero++;
            else if (target[i] & 1)
                break;
        }

        if (countZero == n) // all elements are zero
            return res;

        if (i == n) // all elements are even
        {
            for (int j = 0; j < n; j++)
                target[j] /= 2;
            res++;
        }

        for (int j = i; j < n; j++)
        {
            if (target[j] & 1)
            {
                target[j]--;
                res++;
            }
        }
    }

    return res;
}

int main()
{
    int target[] = { 16, 16, 17 };
    int n = sizeof(target) / sizeof(int);

    std::cout << MinStepsToGetDesiredArray(target, n) << std::endl;

    return 0;
}