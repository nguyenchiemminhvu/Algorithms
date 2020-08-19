/*
https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)

The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one at the bottom of the stack.

For example, let the input stack be

    1  <-- top
    2
    3
    4   
First 4 is inserted at the bottom.
    4 <-- top

Then 3 is inserted at the bottom
    4 <-- top    
    3

Then 2 is inserted at the bottom
    4 <-- top    
    3 
    2
     
Then 1 is inserted at the bottom
    4 <-- top    
    3 
    2
    1
So we need a function that inserts at the bottom of a stack using the above given basic stack function.
*/

#include "Stack.h"
#include <iostream>
using namespace std;

void InsertAtBottom(Stack<int> &S, int value)
{
    if (S.IsEmpty())
    {
        S.Push(value);
    }
    else
    {
        int temp = S.Top();
        S.Pop();

        InsertAtBottom(S, value);

        S.Push(temp);
    }
}

void ReverseStack(Stack<int> &S)
{
    if (S.IsEmpty())
        return;
    
    int temp = S.Top();
    S.Pop();

    ReverseStack(S);

    InsertAtBottom(S, temp);
}

int main()
{
    Stack<int> S;
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Push(4);
    S.Push(5);

    ReverseStack(S);

    while (!S.IsEmpty())
    {
        std::cout << S.Top() << std::endl;
        S.Pop();
    }

    return 0;
}