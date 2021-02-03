#include "LinkedList.h"

int main()
{
    LinkedList<int> L;
    
    L.Clear();
    L.PushBack(1);
    L.PushBack(3);
    L.PushBack(2);
    L.PushBack(5);
    L.PushBack(6);
    L.PushBack(4);
    L.MergeSort();
    L.Print();

    L.Clear();
    L.PushBack(1);
    L.PushBack(3);
    L.PushBack(2);
    L.PushBack(5);
    L.PushBack(6);
    L.PushBack(4);
    L.QuickSort();
    L.Print();
    
    return 0;
}