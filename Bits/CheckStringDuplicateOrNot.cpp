/*
https://www.geeksforgeeks.org/efficiently-check-string-duplicates-without-using-additional-data-structure/

Implement an space efficient algorithm to determine if a string (of characters from ‘a’ to ‘z’) has all unique characters or not. Use additional data structures like count array, hash, etc is not allowed.

Expected Time Complexity : O(n)
Examples :

Input  : str = "aaabbccdaa"
Output : No

Input  : str = "abcd"
Output : Yes
*/

#include <iostream>
#include <string>
using namespace std;

bool IsNotDuplicate(std::string s)
{
    int check = 0;
    for (char c : s)
    {
        int val = c - 'a';

        if (check & (1 << val))
            return false;
        
        check |= (1 << val);
    }

    return true;
}

int main()
{
    std::string s = "nguyenchiemminhvu";

    if (IsNotDuplicate(s))
        std::cout << "No duplicate" << std::endl;
    else
        std::cout << "Duplicate" << std::endl;

    return 0;
}