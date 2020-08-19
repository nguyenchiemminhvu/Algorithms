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

void SortStackUsingStack(Stack<int> &S)
{

}

void SortStackRecursive(Stack<int> &S)
{
    
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