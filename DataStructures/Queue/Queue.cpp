#include "Queue.h"

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

    while (!Q.IsEmpty())
    {
        int n = Q.Front();
        std::cout << n << std::endl;
        Q.Pop();
    }

    return 0;
}