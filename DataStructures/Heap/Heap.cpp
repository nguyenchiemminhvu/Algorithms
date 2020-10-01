#include "Heap.h"
#include <iostream>
using namespace std;

int main()
{
    MinHeap<int> h;
    h.Push(3);
    h.Push(2);
    h.Push(15);
    h.Push(5);
    h.Push(4);
    h.Push(45);
    h.Print();
    std::cout << h.GetMin() << " " << h.GetMax() << std::endl;

    MaxHeap<int> hh;
    hh.Push(3);
    hh.Push(2);
    hh.Push(15);
    hh.Push(5);
    hh.Push(4);
    hh.Push(45);
    hh.Print();
    std::cout << hh.GetMax() << " " << hh.GetMin() << std::endl;

    return 0;
}