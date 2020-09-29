/*
https://www.geeksforgeeks.org/heap-using-stl-c/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> v = { 3, 1, 4, 1, 5, 9 };
    
    std::make_heap(v.begin(), v.end());
    for (int n : v)
        cout << n << " ";
    cout << endl;

    v.push_back(6);

    std::push_heap(v.begin(), v.end());
    for (int n : v)
        cout << n << " ";
    cout << endl;

    std::pop_heap(v.begin(), v.end());
    for (int n : v)
        cout << n << " ";
    cout << endl;

    v.pop_back();
    for (int n : v)
        cout << n << " ";
    cout << endl;

    std::sort_heap(v.begin(), v.end());
    for (int n : v)
        cout << n << " ";
    cout << endl;

    std::make_heap(v.begin(), v.end());
    if (std::is_heap(v.begin(), v.end()))
    {
        std::cout << "Is heap" << std::endl;
    }
    else
    {
        std::cout << "Not heap" << std::endl;
    }

    return 0;
}