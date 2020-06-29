/*
https://www.geeksforgeeks.org/longest-common-prefix-using-divide-and-conquer-algorithm/

Given a set of strings, find the longest common prefix.
Examples:

Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"

We first divide the arrays of string into two parts.
Then we do the same for left part and after that for the right part.
We will do it until and unless all the strings become of length 1.
Now after that, we will start conquering by returning the common prefix of the left and the right strings.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::string SolveLongestCommonPrefix(std::vector<std::string> arr, int left, int right)
{
    return "";
}

int main()
{
    std::vector<std::string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    
    std::string res = SolveLongestCommonPrefix(arr, 0, arr.size() - 1);
    if (res.length())
    {
        std::cout << res << std::endl;
    }
    else
    {
        std::cout << "No common prefix" << std::endl;
    }
    
    
    return 0;
}