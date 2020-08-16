#ifndef __STACK_H__
#define __STACK_H__

#include "LinkedList.h"
#include <assert.h>

template <typename T>
class Stack
{
public:

    Stack()
    {
    }

    ~Stack()
    {
        L.Clear();
    }

    bool Push(const T &v)
    {
        return L.PushFront(v);
    }

    void Pop()
    {
        L.PopFront();
    }

    T Top()
    {
        assert(!IsEmpty());
        return L.Front()->value;
    }

    bool IsEmpty()
    {
        return L.IsEmpty();
    }

    int Size()
    {
        return L.Count();
    }

private:

    LinkedList<T> L;
};


#endif // __STACK_H__