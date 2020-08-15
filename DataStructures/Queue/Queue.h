#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "LinkedList.h"

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
        return true;
    }

    void Pop()
    {

    }

    T Front()
    {
        
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