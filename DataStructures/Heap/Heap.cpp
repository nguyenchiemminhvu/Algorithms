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

    MaxHeap<int> hh(h);
    hh.Print();
    std::cout << hh.GetMax() << " " << hh.GetMin() << std::endl;

    std::cout << "Height: " << h.GetHeight() << " " << hh.GetHeight() << std::endl;
    
    h.PrintPreOrder();
    std::cout << std::endl;

    h.PrintInOrder();
    std::cout << std::endl;
    
    h.PrintPostOrder();
    std::cout << std::endl;
    
    std::vector<int> v = hh.GetHeapData();
    Heap<int>::Sort(v);
    for (int n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}