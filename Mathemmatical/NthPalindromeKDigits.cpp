/*
https://www.geeksforgeeks.org/nth-palindrome-k-digits/

Given two integers n and k, Find the lexicographical nth palindrome of k digits.

Examples:

Input  : n = 5, k = 4
Output : 1441
Explanation:
4 digit lexicographical palindromes are:
1001, 1111, 1221, 1331, 1441
5th palindrome = 1441

Input  :  n = 4, k = 6
Output : 103301
*/

#include <iostream>
#include <cmath>
using namespace std;

int CountDigit(int n)
{
    int res = 0;
    while (n)
    {
        n /= 10;
        res++;
    }
    return res;
}

int NthPalindromeKDigits(int n, int k)
{
    int temp = (k & 1) ? (k / 2) : (k/2 - 1); 
    int firstHalf = (int)pow(10, temp); 
    firstHalf += n - 1;
  
    temp = firstHalf;
    // If k is odd, truncate the last digit 
    if (k & 1) 
        temp /= 10;
    
    int numDigit = CountDigit(temp);

    int secondHalf = 0;
    while (temp)
    { 
        secondHalf = secondHalf * 10 + temp % 10;
        temp /= 10;
    }
    
    return firstHalf * (int)pow(10, numDigit) + secondHalf;
}

int main()
{
    int n = 6, k = 6;
    std::cout << NthPalindromeKDigits(n, k) << std::endl;

    return 0;
}
