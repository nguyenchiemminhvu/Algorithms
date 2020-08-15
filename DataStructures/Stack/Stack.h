#ifndef __STACK_H__
#define __STACK_H__

#include "LinkedList.h"

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
        return true;
    }

    void Pop()
    {

    }

    T Top()
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


#endif // __STACK_H__