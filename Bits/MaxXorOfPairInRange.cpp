/*
https://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/

Given a range [L, R], we need to find two integers in this range such that their XOR is maximum among all possible choices of two integers. More Formally,
given [L, R], find max (A ^ B) where L <= A, B
Examples :

Input  : L = 8
         R = 20
Output : 31
31 is XOR of 15 and 16.  

Input  : L = 1
         R = 3
Output : 3

A simple solution is to generate all pairs, find their XOR values and finally return the maximum XOR value.

An efficient solution is to consider pattern of binary values from L to R. We can see that first bit from L to R either changes from 0 to 1 or it stays 1 i.e. if we take the XOR of any two numbers for maximum value their first bit will be fixed which will be same as first bit of XOR of L and R itself.
After observing the technique to get first bit, we can see that if we XOR L and R, the most significant bit of this XOR will tell us the maximum value we can achieve i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is 1111 because from L to R we have all possible combination of xxx and it is always possible to choose these bits in such a way from two numbers such that their XOR becomes all 1. It is explained below with some examples,

Examples 1:
L = 8    R = 20
L ^ R = (01000) ^ (10100) = (11100)
Now as L ^ R is of form (1xxxx) we
can get maximum XOR as (11111) by 
choosing A and B as 15 and 16 (01111 
and 10000)

Examples 2:
L = 16     R = 20
L ^ R = (10000) ^ (10100) = (00100)
Now as L ^ R is of form (1xx) we can 
get maximum xor as (111) by choosing  
A and B as 19 and 20 (10011 and 10100)
So the solution of this problem depends on the value of (L ^ R) only. We will calculate the L^R value first and then from most significant bit of this value, we will add all 1s to get the final result.
*/

#include <iostream>
using namespace std;

int MaxXorInRange(int left, int right)
{
    int res = left ^ right;
    res |= (res >> 1);
    res |= (res >> 2);
    res |= (res >> 4);
    res |= (res >> 8);
    res |= (res >> 16);

    return res;
}

int main()
{
    int left = 8;
    int right = 20;

    std::cout << MaxXorInRange(left, right) << std::endl;

    return 0;
}