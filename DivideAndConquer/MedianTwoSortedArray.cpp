/*
There are 2 sorted arrays A and B of size n each. 
Write an algorithm to find the median of the array obtained 
after merging the above 2 arrays(i.e. array of length 2n).
The complexity should be O(log(n)).

1) Calculate the medians m1 and m2 of the input arrays ar1[] 
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one    
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays 
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
Examples :

   ar1[] = {1, 12, 15, 26, 38}
   ar2[] = {2, 13, 17, 30, 45}
For above two arrays m1 = 15 and m2 = 17

For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays.

   [15, 26, 38] and [2, 13, 17]
Let us repeat the process for above two subarrays:
    m1 = 26 m2 = 13.
m1 is greater than m2. So the subarrays become

  [15, 26] and [13, 17]
Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
                       = (max(15, 13) + min(26, 17))/2 
                       = (15 + 17)/2
                       = 16
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintArray(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int GetMedian(std::vector<int> v)
{
    if (v.size() & 1)
        return v[v.size() / 2];
    
    return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
}

int FindMedianTwoSortedArray(std::vector<int> a, std::vector<int> b)
{
    if (a.size() == 0)
        return -1;
    if (a.size() == 1)
        return (a[0] + b[0]) / 2;
    if (a.size() == 2)
        return (std::max(a[0], b[0]) + std::min(a[1], b[1])) / 2;

    int medianA = GetMedian(a);
    int medianB = GetMedian(b);

    if (medianA == medianB)
        return medianA;
    
    // Keep array a always smaller than b
    if (medianA > medianB)
    {
        std::vector<int> temp = a;
        a = b;
        b = temp;
    }
    
    if (a.size() & 1)
    {
        a = std::vector<int>(a.begin() + a.size() / 2, a.end());
        b = std::vector<int>(b.begin(), b.begin() + b.size() / 2 + 1);
    }
    else
    {
        a = std::vector<int>(a.begin() + a.size() / 2, a.end());
        b = std::vector<int>(b.begin(), b.begin() + b.size() / 2);
    }
    
    return FindMedianTwoSortedArray(a, b);
}

int main()
{
    std::vector<int> a = { 1, 2, 3, 6 };
    std::vector<int> b = { 4, 6, 8, 10 };
    
    PrintArray(a);
    PrintArray(b);

    if (a.size() != b.size())
    {
        std::cout << "This algorithm doesn't work for arrays of unequal size" << std::endl;
    }
    else
    {
        std::cout << FindMedianTwoSortedArray(a, b) << std::endl;
    }
    

    return 0;
}