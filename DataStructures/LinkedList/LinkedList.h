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
        if (!L)
            return false;

        if (L->value == v)
        {
            ListNode<T> * p = L;
            L = L->next;
            delete p;

            return true;
        }

        ListNode<T> * curNode = L;
        ListNode<T> * prevNode = NULL;
        while (curNode && curNode->value != v)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }

        if (!curNode)
            return false;
        
        prevNode->next = curNode->next;
        delete curNode;

        return true;
    }

    bool DeleteNodes(const T &v)
    {
        if (!L)
            return false;
        
        if (!L->next && L->value == v)
        {
            delete L;
            L = NULL;
            return true;
        }

        ListNode<T> * curNode = L;
        ListNode<T> * prevNode = NULL;
        while (curNode)
        {
            if (curNode->value == v)
            {
                if (!prevNode)
                {
                    L = L->next;
                    delete curNode;
                    curNode = L;
                    continue;
                }

                prevNode->next = curNode->next;
                delete curNode;
                curNode = prevNode->next;
                continue;
            }

            prevNode = curNode;
            curNode = curNode->next;
        }
        
        return true;
    }

    bool DeleteNodeAt(int pos)
    {
        if (!L)
            return false;
        
        int count = Count();
        if (pos < 0 || pos >= count)
            return false;

        ListNode<T> * curNode = L;
        ListNode<T> * prevNode = NULL;
        while (pos)
        {
            prevNode = curNode;
            curNode = curNode->next;
            pos--;
        }

        if (!prevNode) // delete head node
        {
            L = L->next;
            delete curNode;
            return true;
        }
        else
        {
            prevNode->next = curNode->next;
            delete curNode;
            return true;
        }

        return false;
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