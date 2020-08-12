#include "LinkedList.h"

int main()
{
    LinkedList<int> L;
    L.PushBack(1);
    L.PushBack(3);
    L.PushBack(2);
    L.PushBack(5);
    L.PushBack(6);

    L.PushFront(4);
    L.PushFront(7);
    L.PushFront(9);
    L.PushFront(1);
    L.PushFront(2);

    L.Print();

    L.DeleteNode(7);
    L.Print();

    L.DeleteNodeAt(1);
    L.Print();

    L.PushFront(1);
    L.PushBack(1);
    L.Print();

    L.DeleteNodes(1);
    L.Print();

    return 0;
}