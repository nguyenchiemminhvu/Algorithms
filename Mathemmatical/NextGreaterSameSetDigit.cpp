/*
geeksforgeeks.org/find-next-greater-number-set-digits/

Given a number n, find the smallest number that has same set of digits as n and is greater than n. If n is the greatest possible number with its set of digits, then print “not possible”.
Examples:
For simplicity of implementation, we have considered input number as a string.

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"

Following are few observations about the next greater number.

1) If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321.
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
3) For other cases, we need to process the number from rightmost side.
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void Swap(T * a, T * b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

std::string FindNext(std::string n)
{
    int lower;
    for (lower = n.length() - 2; lower >= 0; lower--)
    {
        if (n[lower] < n[lower + 1])
            break;
    }

    if (lower < 0)
        return "NULL";
    
    Swap(&n[lower], &n[n.length() - 1]);

    std::sort(n.begin() + lower + 1, n.end());

    return n;
}

int main()
{
    std::string n = "534976";
    std::cout << FindNext(n) << std::endl;

    return 0;
}
