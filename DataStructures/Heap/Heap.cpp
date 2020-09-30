#include "Heap.h"
#include <iostream>
using namespace std;

int main()
{
    MinHeap<int> h;
    h.Push(4);
    h.Push(6);
    h.Push(2);
    h.Push(8);
    h.Push(5);
    h.Print();

    MaxHeap<int> H;
    H.Push(2);
    H.Push(1);
    H.Push(7);
    H.Push(5);
    H.Push(8);
    H.Print();

    return 0;
}