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

    ListNode<int> * pFind = L.Find(9);
    if (pFind)
    {
        std::cout << "Found " << pFind->value << std::endl;
    }

    ListNode<int> * pGet = L.GetNodeAt(4);
    if (pGet)
    {
        std::cout << "Get node at index 4: " << pGet->value << std::endl;
    }

    ListNode<int> * pGetFromLast = L.GetNodeFromLast(1);
    if (pGetFromLast)
    {
        std::cout << "Get node at index 1 (from last): " << pGetFromLast->value << std::endl;
    }

    return 0;
}