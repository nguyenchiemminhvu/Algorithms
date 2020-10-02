#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

template <typename T>
class MinHeap;

template <typename T>
class MaxHeap;

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

    static bool IsMaxHeap(std::vector<T> v)
    {
        for (int i = 0; i <= ((v.size() - 2) / 2); i++)
        {
            if (v[2 * i + 1] > v[i])
                return false;
            
            if (v[2 * i + 2] > v[i])
                return false;
        }

        return true;
    }

    static bool IsMinHeap(std::vector<T> v)
    {
        for (int i = 0; i <= ((v.size() - 2) / 2); i++)
        {
            if (v[2 * i + 1] < v[i])
                return false;
            
            if (v[2 * i + 2] < v[i])
                return false;
        }
        
        return true;
    }

    static void Sort(std::vector<T> & v)
    {
        for (int i = v.size() / 2 - 1; i >= 0; i--)
        {
            Heap<T>::Heapify(v, v.size(), i);
        }

        for (int i = v.size() - 1; i >= 0; i--)
        {
            std::swap(v[0], v[i]);
            Heap<T>::Heapify(v, i, 0);
        }
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

    int GetHeight()
    {
        return ceil(log2(V.size() + 1)) - 1;
    }

    std::vector<T> GetHeapData()
    {
        return V;
    }

    void Print()
    {
        for (int n : V)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    void PrintPreOrder()
    {
        PrintPreOrderUtil(0);
    }

    void PrintInOrder()
    {
        PrintInOrderUtil(0);
    }

    void PrintPostOrder()
    {
        PrintPostOrderUtil(0);
    }

    virtual T GetMin() = 0;
    virtual T GetMax() = 0;
    virtual void Push(T k) = 0;
    virtual void Pop() = 0;
    virtual void HeapifyUp(int i) = 0;
    virtual void HeapifyDown(int i) = 0;

protected:

    void PrintPreOrderUtil(int i)
    {
        if (i >= V.size())
            return;
        
        std::cout << V[i] << " ";
        PrintPreOrderUtil(GetLeftChildIdx(i));
        PrintPreOrderUtil(GetRightChildIdx(i));
    }

    void PrintInOrderUtil(int i)
    {
        if (i >= V.size())
            return;
        
        PrintInOrderUtil(GetLeftChildIdx(i));
        std::cout << V[i] << " ";
        PrintInOrderUtil(GetRightChildIdx(i));
    }

    void PrintPostOrderUtil(int i)
    {
        if (i >= V.size())
            return;
        
        PrintPostOrderUtil(GetLeftChildIdx(i));
        PrintPostOrderUtil(GetRightChildIdx(i));
        std::cout << V[i] << " ";
    }

protected:

    std::vector<T> V;

private:

    static void Heapify(std::vector<T> & v, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && v[i] < v[l])
            largest = l;
        if (r < n && v[largest] < v[r])
            largest = r;
        
        if (largest != i)
        {
            std::swap(v[i], v[largest]);
            Heap<T>::Heapify(v, n, largest);
        }
    }

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

    MinHeap(MaxHeap<T> h)
    {
        V = h.GetHeapData();

        for (int i = V.size() / 2 - 1; i >= 0; i--)
            HeapifyDown(i);
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

    MaxHeap(MinHeap<T> h)
    {
        V = h.GetHeapData();

        for (int i = V.size() / 2 - 1; i >= 0; i--)
            HeapifyDown(i);
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