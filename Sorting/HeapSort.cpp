/*
Heap sort is a comparison based sorting technique based on Binary Heap data structure.
It is similar to selection sort where we first find the maximum element and place the maximum element at the end.
We repeat the same process for remaining element.

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.

How to build the heap?
Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom up order.

Lets understand with the help of an example:

Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap in top down manner.
*/

#include <iostream>
using namespace std;

void PrintArray(int * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int * arr, int n, int i)
{
    int rootIndex = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    // if left child is larger than root
    if (leftIndex < n && arr[leftIndex] > arr[rootIndex])
        rootIndex = leftIndex;
    
    // if right child is larger than root so far
    if (rightIndex < n && arr[rightIndex] > arr[rootIndex])
        rootIndex = rightIndex;
    
    // if larger is not root
    if (rootIndex != i)
    {
        Swap(&arr[i], &arr[rootIndex]);

        // recursively heapify the affected sub-tree
        Heapify(arr, n, rootIndex);
    }
}

void HeapSort(int * arr, int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }

    // extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        Swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 1, 5, 2, 3, 7, 4, 9 };
    int n = sizeof(arr) / sizeof(int);

    PrintArray(arr, n);
    HeapSort(arr, n);
    PrintArray(arr, n);

    return 0;
}