/*
geeksforgeeks.org/reversing-a-queue/

Give an algorithm for reversing a queue Q. Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue.
dequeue() : Remove an item from front of queue.
empty() : Checks if a queue is empty or not.
Examples:

Input :  Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
Output : Q = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10]

Input : [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]

Approach: For reversing the queue one approach could be to store the elements of the queue in a temporary data structure in a manner such that if we re-insert the elements in the queue they would get inserted in reverse order. So now our task is to choose such data-structure which can serve the purpose. According to the approach, the data-structure should have the property of ‘LIFO’ as the last element to be inserted in the data structure should actually be the first element of the reversed queue. The stack could help in approaching this problem. This will be a two-step process:

Pop the elements from the queue and insert into the stack. (Topmost element of the stack is the last element of the queue)
Pop the elements of the stack to insert back into the queue. (The last element is the first one to be inserted into the queue)
*/

#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void ReverseQueueUsingStack(Queue<int> &Q)
{
    Stack<int> S;

    while (!Q.IsEmpty())
    {
        S.Push(Q.Front());
        Q.Pop();
    }

    while (!S.IsEmpty())
    {
        Q.Push(S.Top());
        S.Pop();
    }
}

void ReverseQueueRecursive(Queue<int> &Q)
{
    if (Q.IsEmpty())
        return;
    
    int temp = Q.Front();
    Q.Pop();

    ReverseQueueRecursive(Q);

    Q.Push(temp);
}

int main()
{
    Queue<int> Q;

    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    Q.Push(4);
    Q.Push(5);
    Q.Push(6);
    Q.Push(7);
    Q.Push(8);
    ReverseQueueRecursive(Q);
    while (!Q.IsEmpty())
    {
        std::cout << Q.Front() << " ";
        Q.Pop();
    }

    std::cout << std::endl;

    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    Q.Push(4);
    Q.Push(5);
    Q.Push(6);
    Q.Push(7);
    Q.Push(8);
    ReverseQueueUsingStack(Q);
    while (!Q.IsEmpty())
    {
        std::cout << Q.Front() << " ";
        Q.Pop();
    }

    return 0;
}