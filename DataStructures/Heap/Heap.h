#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
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

    int GetParentIdx(int i)
    {
        int p = (i - 1) / 2;
        if (p < V.size())
            return p;

        return -1;
    }

    int GetLeftChildIdx(int i)
    {
        int p = (2 * i) + 1;
        if (p < V.size())
            return p;
        
        return -1;
    }

    int GetRightChildIdx(int i)
    {
        int p = (2 * i) + 2;
        if (p < V.size())
            return p;
        
        return -1;
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
    virtual void HeapifyUp(int i) = 0;
    virtual void HeapifyDown(int i) = 0;

protected:

    std::vector<T> V;

};

template <typename T>
class MinHeap : public Heap<T>
{
    using Heap<T>::V;
    using Heap<T>::GetParentIdx;
    using Heap<T>::GetLeftChildIdx;
    using Heap<T>::GetRightChildIdx;
    
public:
    MinHeap()
    {

    }

    ~MinHeap()
    {

    }

    virtual T GetMin()
    {
        if (V.empty())
            return INT_MAX;
        
        return V[0];
    }

    virtual T GetMax()
    {
        int res = V[V.size() / 2];
        for (int i = V.size() / 2 + 1; i < V.size(); i++)
        {
            res = std::max(res, V[i]);
        }

        return res;
    }

    virtual void Push(T k)
    {
        V.push_back(k);
        HeapifyUp(V.size() - 1);
    }

    virtual void Pop()
    {
        if (V.empty())
            return;
        
        std::swap(V[0], V[V.size() - 1]);
        V.pop_back();

        HeapifyDown(0);
    }

    virtual void HeapifyUp(int i)
    {
        while (i && V[GetParentIdx(i)] > V[i])
        {
            std::swap(V[i], V[GetParentIdx(i)]);
            i = GetParentIdx(i);
        }
    }

    virtual void HeapifyDown(int i)
    {
        int leftIdx = GetLeftChildIdx(i);
        int rightIdx = GetRightChildIdx(i);

        int smallestIdx = i;
        if (leftIdx != -1 && V[leftIdx] < V[i])
            smallestIdx = leftIdx;
        if (rightIdx != -1 && V[rightIdx] < V[smallestIdx])
            smallestIdx = rightIdx;
        
        if (smallestIdx != i)
        {
            std::swap(V[i], V[smallestIdx]);
            HeapifyDown(smallestIdx);
        }
    }

protected:
    
    
};

template <typename T>
class MaxHeap : public Heap<T>
{
    using Heap<T>::V;
    using Heap<T>::GetParentIdx;
    using Heap<T>::GetLeftChildIdx;
    using Heap<T>::GetRightChildIdx;

public:
    MaxHeap()
    {

    }

    ~MaxHeap()
    {

    }

    virtual T GetMin()
    {
        int res = V[V.size() / 2];
        for (int i = V.size() / 2 + 1; i < V.size(); i++)
        {
            res = std::min(res, V[i]);
        }

        return res;
    }

    virtual T GetMax()
    {
        if (V.empty())
            return INT_MIN;
        
        return V[0];
    }

    virtual void Push(T k)
    {
        V.push_back(k);
        HeapifyUp(V.size() - 1);
    }

    virtual void Pop()
    {
        if (V.empty())
            return;
        
        std::swap(V[0], V[V.size() - 1]);
        V.pop_back();

        HeapifyDown(0);
    }

    virtual void HeapifyUp(int i)
    {
        while (i != -1 && V[GetParentIdx(i)] < V[i])
        {
            std::swap(V[i], V[GetParentIdx(i)]);
            i = GetParentIdx(i);
        }
    }

    virtual void HeapifyDown(int i)
    {
        int leftIdx = GetLeftChildIdx(i);
        int rightIdx = GetRightChildIdx(i);

        int largestIdx = i;
        if (leftIdx != -1 && V[leftIdx] > V[i])
            largestIdx = leftIdx;
        if (rightIdx != -1 && V[rightIdx] > V[largestIdx])
            largestIdx = rightIdx;
        
        if (largestIdx != i)
        {
            std::swap(V[i], V[largestIdx]);
            HeapifyDown(largestIdx);
        }
    }

protected:

    
};

#endif // __HEAP_H__