/*
https://www.geeksforgeeks.org/next-greater-element/

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:

For any array, rightmost element always has next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.
For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1

This problem can be solved by using a stack.
We traverse the array once.
1. If the stack is empty or the current element is smaller than top element of the stack, then push the current element on the stack.
2. If the current element is greater than top element of the stack, then this is the next greater element of the top element. Keep poping elements from the stack till a larger element than the current element is found on the stack or till the stack becomes empty. Push the current element on the stack.
3. Repeat steps 1 and 2 till the end of array is reached.
4. Finally pop remaining elements from the stack and print null for them.
Please note that at any instance, the stack will always be in sorted order having least element at the top and largest element at the bottom.
*/

#include "Stack.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::map<int, int> NextGreaterElement(std::vector<int> arr)
{
    std::map<int, int> res;
    
    Stack<int> S;
    S.Push(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        while (!S.IsEmpty() && S.Top() < arr[i])
        {
            res[S.Top()] = arr[i];
            S.Pop();
        }
        S.Push(arr[i]);
    }

    while (!S.IsEmpty())
    {
        res[S.Top()] = -1;
        S.Pop();
    }

    return res;
}

int main()
{
    std::vector<int> arr = {11, 13, 21, 3, 7, 95, 50}; 
    std::map<int, int> NGE = NextGreaterElement(arr);

    for (int n : arr)
    {
        std::cout << n << " -> " << NGE[n] << std::endl;
    }

    return 0;
}