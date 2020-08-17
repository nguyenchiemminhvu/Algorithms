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

    L.Reverse();
    L.Print();

    L.Reverse();
    L.Print();

    L.PushBack(2);
    L.PushBack(2);
    L.PushBack(3);
    L.PushBack(3);
    L.PushBack(9);
    L.RemoveDuplicates();
    L.Print();

    L.Clear();
    L.InsertSortedOrder(4);
    L.InsertSortedOrder(3);
    L.InsertSortedOrder(6);
    L.InsertSortedOrder(8);
    L.InsertSortedOrder(1);
    L.InsertSortedOrder(9);
    L.InsertSortedOrder(2);
    L.InsertSortedOrder(5);
    L.InsertSortedOrder(7);
    L.Print();
    
    L.Clear();
    L.PushBack(1);
    L.PushBack(3);
    L.PushBack(2);
    L.PushBack(5);
    L.PushBack(6);
    L.PushBack(4);
    L.MergeSort();
    L.Print();

    ListNode<int> * pFront = L.Front();
    if (pFront)
        std::cout << "Front: " << pFront->value << std::endl;
    
    ListNode<int> * pBack = L.Back();
    if (pBack)
        std::cout << "Front: " << pBack->value << std::endl;
    
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

    if (L.IsLoop())
    {
        std::cout << "Loop" << std::endl;
    }
    else
    {
        std::cout << "Not loop" << std::endl;
    }

    L.Clear();
    L.PushBack(1);
    L.PushBack(2);
    L.PushBack(3);
    L.PushBack(3);
    L.PushBack(2);
    L.PushBack(1);
    if (L.IsPalindrome())
    {
        std::cout << "Palindrome" << std::endl;
    }
    else
    {
        std::cout << "Not palindrome" << std::endl;
    }

    L.Print();

    return 0;
}