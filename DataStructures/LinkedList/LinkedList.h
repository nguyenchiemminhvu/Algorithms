#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <limits.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

template <typename T>
class ListNode
{
public:
    ListNode(const T &v)
        : value(v), next(NULL)
    {
    }

    ~ListNode()
    {
    }

public:
    T value;
    ListNode * next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList() 
        : L(NULL)
    {

    }

    ~LinkedList() 
    {
        while (L)
        {
            ListNode<T> * p = L;
            L = L->next;
            delete p;
        }

        L = NULL;
    }

    void Print()
    {
        ListNode<T> * p = L;
        while (p)
        {
            std::cout << p->value << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    int Count()
    {
        int count = 0;

        ListNode<T> * p = L;
        while (p)
        {
            count++;
            p = p->next;
        }

        return count;
    }

    bool PushBack(const T &v)
    {
        ListNode<T> * NewNode = CreateNode(v);
        if (!NewNode)
            return false;

        if (L == NULL)
        {
            L = NewNode;
        }
        else
        {
            ListNode<T> * p = L;
            while (p->next)
            {
                p = p->next;
            }
            p->next = NewNode;
        }

        return true;
    }

    bool PushFront(const T &v)
    {
        ListNode<T> * NewNode = CreateNode(v);
        if (!NewNode)
            return false;

        if (L == NULL)
        {
            L = NewNode;
        }
        else
        {
            NewNode->next = L;
            L = NewNode;
        }

        return true;
    }

    bool DeleteNode(const T &v)
    {
        
    }

    bool DeleteNodes(const T &v)
    {

    }

    bool DeleteNodeAt(const int &pos)
    {

    }

public:
    ListNode<T> * L;

private:

    ListNode<T> * CreateNode(const T &v)
    {
        ListNode<T> * node = new ListNode<T>(v);
        return node;
    }
};

#endif // __LINKED_LIST_H__