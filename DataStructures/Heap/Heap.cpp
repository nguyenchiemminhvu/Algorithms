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
    h.Push(10);
    h.Push(7);
    h.Print();
    std::cout << h.GetMin() << " " << h.GetMax() << std::endl;

    MaxHeap<int> hh;
    hh.Push(3);
    hh.Push(2);
    hh.Push(15);
    hh.Push(5);
    hh.Push(4);
    hh.Push(45);
    hh.Push(10);
    hh.Push(7);
    hh.Print();
    std::cout << hh.GetMax() << " " << hh.GetMin() << std::endl;

    std::cout << "Height: " << h.GetHeight() << " " << hh.GetHeight() << std::endl;

    std::vector<int> v = { 90, 15, 10, 7, 12, 2, 7, 3 };
    Heap<int>::Sort(v);
    for (int n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}