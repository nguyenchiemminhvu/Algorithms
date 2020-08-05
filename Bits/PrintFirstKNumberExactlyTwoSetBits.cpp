/*
https://www.geeksforgeeks.org/print-first-n-numbers-with-exactly-two-set-bits/

Given a number n, print first n positive integers with exactly two set bits in their binary representation.

Examples :

Input: n = 3
Output: 3 5 6
The first 3 numbers with two set bits are 3 (0011),
5 (0101) and 6 (0110)

Input: n = 5
Output: 3 5 6 9 10 12

A Simple Solution is to consider all positive integers one by one starting from 1. For every number, check if it has exactly two sets bits. If a number has exactly two set bits, print it and increment count of such numbers.

An Efficient Solution is to directly generate such numbers. If we clearly observe the numbers, we can rewrite them as given below pow(2,1)+pow(2,0), pow(2,2)+pow(2,0), pow(2,2)+pow(2,1), pow(2,3)+pow(2,0), pow(2,3)+pow(2,1), pow(2,3)+pow(2,2), ………
*/

#include <iostream>
#include <vector>
using namespace std;

std::vector<int> FirstKTwoSetBits(int k)
{
    std::vector<int> res;
    for (int i = 1; ; i++)
    {
        for (int j = 0; j < i; j++)
        {
            res.push_back((1 << i) + (1 << j));
            
            k--;
            if (k == 0)
                return res;
        }
    }

    return res;
}

int main()
{
    int k = 5;

    std::vector<int> twoSetBitsArr = FirstKTwoSetBits(k);
    for (int n : twoSetBitsArr)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}