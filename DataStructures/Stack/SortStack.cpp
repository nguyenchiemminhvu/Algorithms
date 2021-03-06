/*
https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

Given a stack of integers, sort it in ascending order using another temporary stack.

Examples:

Input : [34, 3, 31, 98, 92, 23]
Output : [3, 23, 31, 34, 92, 98]

Input : [3, 5, 1, 4, 2, 8]
Output : [1, 2, 3, 4, 5, 8]
*/

#include "Stack.h"
#include <iostream>
using namespace std;

void SortedInsert(Stack<int> &S, int value)
{
    if (S.IsEmpty() || value < S.Top())
    {
        S.Push(value);
    }
    else
    {
        int temp = S.Top();
        S.Pop();
        SortedInsert(S, value);
        S.Push(temp);
    }
}

void SortStackRecursive(Stack<int> &S)
{
    if (S.IsEmpty())
        return;
    
    int temp = S.Top();
    S.Pop();

    SortStackRecursive(S);

    SortedInsert(S, temp);
}

void SortStackUsingStack(Stack<int> &S)
{
    Stack<int> SS;

    while (!S.IsEmpty())
    {
        int temp = S.Top();
        S.Pop();

        while (!SS.IsEmpty() && temp < SS.Top())
        {
            S.Push(SS.Top());
            SS.Pop();
        }

        SS.Push(temp);
    }

    while (!SS.IsEmpty())
    {
        S.Push(SS.Top());
        SS.Pop();
    }
}

int main()
{
    Stack<int> S;

    S.Push(1);
    S.Push(5);
    S.Push(2);
    S.Push(3);
    S.Push(1);
    S.Push(4);
    S.Push(7);
    S.Push(6);
    SortStackRecursive(S);
    while (!S.IsEmpty())
    {
        std::cout << S.Top() << " ";
        S.Pop();
    }
    std::cout << std::endl;

    S.Push(1);
    S.Push(5);
    S.Push(2);
    S.Push(3);
    S.Push(1);
    S.Push(4);
    S.Push(7);
    S.Push(6);
    SortStackUsingStack(S);
    while (!S.IsEmpty())
    {
        std::cout << S.Top() << " ";
        S.Pop();
    }
    std::cout << std::endl;

    return 0;
}