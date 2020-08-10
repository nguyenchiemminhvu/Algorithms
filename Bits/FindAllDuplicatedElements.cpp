/*
https://www.geeksforgeeks.org/find-duplicates-of-array-using-bit-array/

You have an array of N numbers, where N is at most 32,000. The array may have duplicate entries and you do not know what N is. With only 4 Kilobytes of memory available, how would print all duplicate elements in the array ?.

Examples:

Input : arr[] = {1, 5, 1, 10, 12, 10}
Output : 1 10
1 and 10 appear more than once in given
array.

Input : arr[] = {50, 40, 50}
Output : 50
*/

#include <iostream>
#include <vector>
using namespace std;

std::vector<int> FindAllDuplicatedElements(std::vector<int> v)
{
    std::vector<int> res;

    std::vector<int> check((3200000 >> 5), 0);
    for (int n : v)
    {
        int index = (n >> 5);
        int bitNo = (n & 31);

        if (check[index] & (1 << bitNo))
        {
            res.push_back(n);
        }
        else
        {
            check[index] |= (1 << bitNo);
        }
    }

    return res;
}

int main()
{
    std::vector<int> v = { 1, 5, 1, 10, 9, 9, 7 };
    
    std::vector<int> dup = FindAllDuplicatedElements(v);
    for (int n : dup)
    {
        std::cout << n << std::endl;
    }

    return 0;
}