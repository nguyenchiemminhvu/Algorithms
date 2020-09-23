/*
https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

Given two sorted arrays, find their union and intersection.
Example:

Input : arr1[] = {1, 3, 4, 5, 7}
        arr2[] = {2, 3, 5, 6} 
Output : Union : {1, 2, 3, 4, 5, 6, 7} 
         Intersection : {3, 5}

Input : arr1[] = {2, 5, 6}
        arr2[] = {4, 6, 8, 10} 
Output : Union : {2, 4, 5, 6, 8, 10} 
         Intersection : {6}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> Intersect(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> res;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ia = 0, ib = 0;

    while (ia < a.size() && ib < b.size())
    {
        if (a[ia] < b[ib])
        {
            ia++;
        }
        else if (a[ia] > b[ib])
        {
            ib++;
        }
        else
        {
            res.push_back(a[ia]);
            ia++;
            ib++;
        }
    }

    return res;
}

int main()
{
    std::vector<int> a = { 1, 2, 4, 5, 6 };
    std::vector<int> b = { 2, 3, 5, 7 };

    std::vector<int> i = Intersect(a, b);
    for (int n : i)
        std::cout << n << " ";
    std::cout << endl;

    return 0;
}