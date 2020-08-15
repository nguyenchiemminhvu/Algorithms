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

private:

    LinkedList<T> L;
};


#endif // __STACK_H__