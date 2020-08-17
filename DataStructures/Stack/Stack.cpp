#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack<int> S;

    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Push(4);
    S.Push(5);
    S.Push(6);
    S.Push(7);

    while (!S.IsEmpty())
    {
        int n = S.Top();
        std::cout << n << std::endl;
        S.Pop();
    }
    
    return 0;
}