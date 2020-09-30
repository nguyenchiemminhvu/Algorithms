#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Heap
{
public:
    Heap()
    {

    }

    ~Heap()
    {

    }

    int GetParent(int i)
    {
        return (i - 1) / 2;
    }

    int GetLeftChild(int i)
    {
        return (2 * i) + 1;
    }

    int GetRightChild(int i)
    {
        return (2 * i) + 2;
    }

    void Print()
    {
        for (int n : V)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    void Sort()
    {

    }

    virtual T GetMin() = 0;
    virtual T GetMax() = 0;
    virtual void Push(T k) = 0;
    virtual void Pop() = 0;
    virtual void Delete(int i) = 0;
    virtual void Heapify() = 0;

protected:

    std::vector<T> V;

};

template <typename T>
class MinHeap : public Heap<T>
{
    using Heap<T>::V;
    
public:
    MinHeap()
    {

    }

    ~MinHeap()
    {

    }

    virtual T GetMin()
    {
        return V[0];
    }

    virtual T GetMax()
    {
        return V[V.size() - 1];
    }

    virtual void Push(T k)
    {

    }

    virtual void Pop()
    {

    }

    virtual void Delete(int i)
    {

    }

    virtual void Heapify()
    {

    }

protected:
    
    
};

template <typename T>
class MaxHeap : public Heap<T>
{
    using Heap<T>::V;

public:
    MaxHeap()
    {

    }

    ~MaxHeap()
    {

    }

    virtual T GetMin()
    {
        return V[V.size() - 1];
    }

    virtual T GetMax()
    {
        return V[0];
    }

    virtual void Push(T k)
    {

    }

    virtual void Pop()
    {

    }

    virtual void Delete(int i)
    {

    }

    virtual void Heapify()
    {
        
    }

protected:

    
};

#endif // __HEAP_H__