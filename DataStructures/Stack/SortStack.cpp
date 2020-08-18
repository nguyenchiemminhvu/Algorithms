/*
https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

Given a stack of integers, sort it in ascending order using another temporary stack.

Examples:

Input : [34, 3, 31, 98, 92, 23]
Output : [3, 23, 31, 34, 92, 98]

Input : [3, 5, 1, 4, 2, 8]
Output : [1, 2, 3, 4, 5, 8]

Create a temporary stack say tmpStack.
While input stack is NOT empty do this:
Pop an element from input stack call it temp
while temporary stack is NOT empty and top of temporary stack is greater than temp,
pop from temporary stack and push it to the input stack
push temp in temporary stack
The sorted numbers are in tmpStack
*/

#include "Stack.h"
#include <iostream>
using namespace std;

void SortStack(Stack<int> &S)
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

    SortStack(S);

    while (!S.IsEmpty())
    {
        std::cout << S.Top() << " ";
        S.Pop();
    }
    std::cout << std::endl;

    return 0;
}