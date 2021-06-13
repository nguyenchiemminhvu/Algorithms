/*
https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/

Given a positive integer, find the maximum integer possible by doing at-most K swap operations on its digits.
Examples: 

Input: M = 254, K = 1
Output: 524
Swap 5 with 2 so number becomes 524

Input: M = 254, K = 2
Output: 542
Swap 5 with 2 so number becomes 524
Swap 4 with 2 so number becomes 542

Input: M = 68543, K = 1 
Output: 86543
Swap 8 with 6 so number becomes 86543

Input: M = 7599, K = 2
Output: 9975
Swap 9 with 5 so number becomes 7995
Swap 9 with 7 so number becomes 9975

Input: M = 76543, K = 1 
Output: 76543
Explanation: No swap is required.

Input: M = 129814999, K = 4
Output: 999984211
Swap 9 with 1 so number becomes 929814991
Swap 9 with 2 so number becomes 999814291
Swap 9 with 8 so number becomes 999914281
Swap 1 with 8 so number becomes 999984211
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void KSwapGetMaxNumber(std::string N, int K, std::string &res, int cur)
{
    if (K == 0)
        return;
    
    int temp_max_element = N[cur];
    for (int i = cur + 1; i < N.length(); i++)
    {
        if (temp_max_element < N[i])
            temp_max_element = N[i];
    }

    if (N[cur] != temp_max_element)
    {
        K--;
    }

    for (int i = cur; i < N.length(); i++)
    {
        if (N[i] == temp_max_element)
        {
            std::swap(N[cur], N[i]);

            if (N > res)
                res = N;
            
            KSwapGetMaxNumber(N, K, res, cur + 1);

            std::swap(N[cur], N[i]);
        }
    }
}

int main()
{
    std::string N = "129814999";
    int K = 4;

    std::string res = N;
    KSwapGetMaxNumber(N, K, res, 0);
    std::cout << res << std::endl;

    return 0;
}