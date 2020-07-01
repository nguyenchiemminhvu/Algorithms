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
#include <string>
using namespace std;

std::string NthPalindromeKDigits(std::string n)
{

}

int main()
{
    std::string n = "534976";
    std::cout << NthPalindromeKDigits(n) << std::endl;

    return 0;
}
