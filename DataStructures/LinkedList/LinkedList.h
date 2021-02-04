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
        : L(NULL), LEnd(NULL)
    {

    }

    LinkedList(const LinkedList<T> &other)
    {
        Clear();

        ListNode<T> * p = other.L;
        while (p)
        {
            PushFront(p->value);
            p = p->next;
        }

        Reverse();
    }

    LinkedList(ListNode<T> * LL)
    {
        Clear();

        ListNode<T> * p = LL;
        while (p)
        {
            PushFront(p->value);
            p = p->next;
        }

        Reverse();
    }

    LinkedList<T> operator = (const LinkedList<T> &other)
    {
        Clear();

        ListNode<T> * p = other.L;
        while (p)
        {
            PushFront(p->value);
            p = p->next;
        }

        Reverse();
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
            LEnd = NewNode;
        }
        else
        {
            ListNode<T> * p = LEnd;
            p->next = NewNode;
            LEnd = NewNode;
        }

        return true;
    }

    bool PopBack()
    {
        if (!L)
            return false;
        
        if (!L->next)
        {
            delete L;
            L = NULL;
            LEnd = NULL;
        }
        else
        {
            ListNode<T> * p = L;
            ListNode<T> * prev = NULL;
            while (p != LEnd)
            {
                prev = p;
                p = p->next;
            }
            delete p;
            prev->next = NULL;
            LEnd = prev;
        }

        return true;
    }

    ListNode<T> * Back()
    {
        return LEnd;
    }

    bool PushFront(const T &v)
    {
        ListNode<T> * NewNode = CreateNode(v);
        if (!NewNode)
            return false;

        if (L == NULL)
        {
            L = NewNode;
            LEnd = NewNode;
        }
        else
        {
            NewNode->next = L;
            L = NewNode;
        }

        return true;
    }

    bool PopFront()
    {
        if (!L)
            return false;
        
        if (!L->next)
        {
            delete L;
            L = NULL;
            LEnd = NULL;
        }
        else
        {
            ListNode<T> * p = L;
            L = L->next;
            delete p;
        }
        
        return true;
    }

    ListNode<T> * Front()
    {
        return L;
    }

    bool InsertSortedOrder(const T &v)
    {
        ListNode<T> * NewNode = CreateNode(v);
        if (!NewNode)
            return false;
        
        if (L == NULL)
        {
            L = NewNode;
            LEnd = NewNode;
        }
        else
        {
            ListNode<T> * curNode = L;
            ListNode<T> * prevNode = NULL;
            while (curNode && curNode->value < v)
            {
                prevNode = curNode;
                curNode = curNode->next;
            }

            if (!prevNode)
            {
                NewNode->next = L;
                L = NewNode;
            }
            else
            {
                prevNode->next = NewNode;
                NewNode->next = curNode;
                if (!curNode)
                {
                    LEnd = NewNode;
                }
            }
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
        LEnd = NULL;
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

        if (!prevNode->next)
        {
            LEnd = prevNode;
        }

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

        RefreshLEnd();
        
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
            if (!L)
                LEnd = NULL;
            return true;
        }
        else
        {
            prevNode->next = curNode->next;
            delete curNode;
            if (!prevNode->next)
                LEnd = prevNode;
            return true;
        }

        return false;
    }

    void RemoveDuplicates()
    {
        ListNode<T> * curNode = L;
        ListNode<T> * prevNode = NULL;

        while (curNode && curNode->next)
        {
            if (curNode->value == curNode->next->value)
            {
                if (!prevNode)
                {
                    prevNode = curNode;
                    curNode = curNode->next;
                    delete prevNode;
                    prevNode = NULL;
                    continue;
                }
                else
                {
                    prevNode->next = curNode->next;
                    delete curNode;
                    curNode = prevNode->next;
                    continue;
                }
            }

            prevNode = curNode;
            curNode = curNode->next;
        }

        RefreshLEnd();
    }

    void MergeSort()
    {
        MergeSortUtil(L);
        RefreshLEnd();
    }

    void QuickSort()
    {
        ListNode<T> * tail = LEnd;
        L = QuickSortUtil(L, tail);

        RefreshLEnd();
    }

    void Reverse()
    {
        LEnd = L;

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

    bool IsEmpty()
    {
        return L == NULL;
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
        if (!L || !L->next)
            return true;

        bool res = true;

        ListNode<T> * LA = NULL;
        ListNode<T> * LB = NULL;
        FrontBackSplit(L, LA, LB);

        ListNode<T> * pa = LA;
        Reverse(LB);
        ListNode<T> * pb = LB;

        while (pa && pb)
        {
            if (pa->value != pb->value)
            {
                res = false;
                break;
            }
            
            pa = pa->next;
            pb = pb->next;
        }

        ListNode<T> * pLastA = LA;
        Reverse(LB);
        while (pLastA->next)
        {
            pLastA = pLastA->next;
        }
        pLastA->next = LB;

        return res;
    }

    bool IsSorted()
    {
        if (!L || !L->next)
            return true;
        
        ListNode<T> * p = L->next;
        ListNode<T> * prev = L;

        while (p)
        {
            if (prev->value > p->value)
                return false;
            
            prev = p;
            p = p->next;
        }

        return true;
    }

public:

    ListNode<T> * L;
    ListNode<T> * LEnd;

private:

    ListNode<T> * CreateNode(const T &v)
    {
        ListNode<T> * node = new ListNode<T>(v);
        return node;
    }

    void RefreshLEnd()
    {
        if (!L)
        {
            LEnd = NULL;
        }
        else
        {
            ListNode<T> * p = L;
            while (p->next)
            {
                p = p->next;
            }
            LEnd = p;
        }
    }

    void MergeSortUtil(ListNode<T> *&LL)
    {
        if (!LL || !LL->next)
            return;
        
        ListNode<T> * pLeft = NULL;
        ListNode<T> * pRight = NULL;
        FrontBackSplit(LL, pLeft, pRight);
        MergeSortUtil(pLeft);
        MergeSortUtil(pRight);
        LL = SortedMerge(pLeft, pRight);
    }

    ListNode<T> * SortedMerge(ListNode<T> * LA, ListNode<T> * LB)
    {
        if (!LA)
            return LB;
        if (!LB)
            return LA;

        ListNode<T> * res = NULL;

        if (LA->value <= LB->value)
        {
            res = LA;
            res->next = SortedMerge(LA->next, LB);
        }
        else
        {
            res = LB;
            res->next = SortedMerge(LA, LB->next);
        }

        return res;
    }

    void FrontBackSplit(ListNode<T> * LL, ListNode<T> *&LA, ListNode<T> *&LB)
    {
        ListNode<T> * prevSlow = NULL;
        ListNode<T> * pSlow = LL;
        ListNode<T> * pFast = LL;
        while (pFast && pFast->next)
        {
            prevSlow = pSlow;
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        LA = LL;
        LB = pSlow;
        if (prevSlow)
            prevSlow->next = NULL;
    }

    ListNode<T> * QuickSortUtil(ListNode<T> * root, ListNode<T> * tail)
    {
        if (!root || root == tail)
            return root;
        
        ListNode<T> * newRoot = NULL;
        ListNode<T> * newTail = NULL;
        
        ListNode<T> * pivot = QuickSortPartition(root, tail, newRoot, newTail);
        if (newRoot != pivot)
        {
            ListNode<T> * pEnd = newRoot;
            while (pEnd->next != pivot)
            {
                pEnd = pEnd->next;
            }
            pEnd->next = NULL;

            newRoot = QuickSortUtil(newRoot, pEnd);

            pEnd = GetTailUtil(newRoot);
            pEnd->next = pivot;
        }

        pivot->next = QuickSortUtil(pivot->next, newTail);

        return newRoot;
    }

    ListNode<T> * QuickSortPartition(   ListNode<T> * root, ListNode<T> * tail, 
                                        ListNode<T> *& newRoot, ListNode<T> *& newTail)
    {
        ListNode<T> * prev = NULL;
        ListNode<T> * cur = root;
        ListNode<T> * pivot = tail;
        ListNode<T> * pEnd = pivot;

        while (cur != pivot)
        {
            if (cur->value < pivot->value)
            {
                if (!newRoot)
                {
                    newRoot = cur;
                }

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }

                ListNode<T> * temp = cur->next;
                cur->next = NULL;
                pEnd->next = cur;
                pEnd = cur;
                cur = temp;
            }
        }

        if (!newRoot)
        {
            newRoot = pivot;
        }

        newTail = pEnd;

        return pivot;
    }

    ListNode<T> * GetTailUtil(ListNode<T> * root)
    {
        if (!root)
            return root;
        
        ListNode<T> * p = root;
        while (p->next)
        {
            p = p->next;
        }

        return p;
    }

    void Reverse(ListNode<T> *&LL)
    {
        ListNode<T> * prev = NULL;
        ListNode<T> * cur = LL;
        ListNode<T> * next = NULL;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        LL = prev;
    }
};

#endif // __LINKED_LIST_H__