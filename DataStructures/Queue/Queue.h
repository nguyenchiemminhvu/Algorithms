#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "LinkedList.h"
#include <assert.h>

template <typename T>
class Queue
{
public:

    Queue()
    {
    }

    ~Queue()
    {
        L.Clear();
    }

    bool Push(const T &v)
    {
        return L.PushBack(v);
    }

    void Pop()
    {
        L.PopFront();
    }

    T Front()
    {
        assert(!IsEmpty());
        return L.Front();
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

#endif // __QUEUE_H__