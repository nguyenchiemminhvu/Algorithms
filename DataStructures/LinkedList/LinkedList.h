#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <limits.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
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
        Clear();
    }

    LinkedList<T> Clone()
    {
        LinkedList<T> CL;
        
        ListNode<T> * p = L;
        while (p)
        {
            CL.PushBack(p->value);
            p = p->next;
        }

        return CL;
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

    void Clear()
    {
        while (L)
        {
            ListNode<T> * p = L;
            L = L->next;
            delete p;
        }

        L = NULL;
    }

    ListNode<T> * Find(const int &v)
    {
        ListNode<T> * p = L;
        while (p && p->value != v)
        {
            p = p->next;
        }
        return p;
    }

    ListNode<T> * GetNodeAt(int pos)
    {
        if (pos < 0)
            return NULL;
        
        ListNode<T> * p = L;
        while (p && pos)
        {
            p = p->next;
            pos--;
        }
        return p;
    }

    ListNode<T> * GetNodeFromLast(int pos)
    {
        if (pos < 0)
            return NULL;
        
        int count = Count();
        if (pos >= count)
            return NULL;
        
        ListNode<T> * p = L;
        for (int i = 1; i < count - pos; i++)
        {
            p = p->next;
        }

        return p;
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

    void RemoveDuplicates()
    {

    }

    void RemoveAllOccurrencesOfDuplicates()
    {
        
    }

    void Reverse()
    {
        ListNode<T> * prev = NULL;
        ListNode<T> * cur = L;
        ListNode<T> * next = NULL;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        L = prev;
    }

    bool IsLoop()
    {
        ListNode<T> * pFast = L;
        ListNode<T> * pSlow = L;

        while (pSlow && pFast && pFast->next)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;

            if (pSlow == pFast)
                return true;
        }

        return false;
    }

    bool IsPalindrome()
    {
        std::stack<T> S;
        ListNode<T> * p = L;
        while (p)
        {
            S.push(p->value);
            p = p->next;
        }

        p = L;
        while (p)
        {
            if (p->value != S.top())
                return false;

            p = p->next;
            S.pop();
        }

        return true;
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