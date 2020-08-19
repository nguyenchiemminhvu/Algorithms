/*
https://www.geeksforgeeks.org/sorting-queue-without-extra-space/

Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The operations allowed on queue are :

enqueue() : Adds an item to rear of queue. In C++ STL queue, this function is called push().
dequeue() : Removes an item from front of queue. In C++ STL queue, this function is called pop().
isEmpty() : Checks if a queue is empty. In C++ STL queue, this function is called empty().
Examples :

Input : A queue with elements 
        11  5  4  21 
Output : Modified queue with 
         following elements
        4 5 11 21

Input : A queue with elements 
        3  2  1  2
Output : Modified queue with 
         following elements
        1 2 2 3
*/

#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void SortQueue(Queue<int> &Q)
{
    Stack<int> S;
    
    while (!Q.IsEmpty())
    {
        S.Push(Q.Front());
        Q.Pop();
    }

    Stack<int> SS;
    while (!S.IsEmpty())
    {
        int temp = S.Top();
        S.Pop();

        while (!SS.IsEmpty() && temp > SS.Top())
        {
            S.Push(SS.Top());
            SS.Pop();
        }

        SS.Push(temp);
    }

    while (!SS.IsEmpty())
    {
        Q.Push(SS.Top());
        SS.Pop();
    }
}

int main()
{
    Queue<int> Q;

    Q.Push(1);
    Q.Push(6);
    Q.Push(3);
    Q.Push(2);
    Q.Push(5);
    Q.Push(4);

    SortQueue(Q);

    while (!Q.IsEmpty())
    {
        std::cout << Q.Front() << " ";
        Q.Pop();
    }
    std::cout << std::endl;

    return 0;
}