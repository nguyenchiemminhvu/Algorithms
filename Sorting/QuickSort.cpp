/*
QuickSort is a Divide and Conquer algorithm.
It picks an element as pivot and partitions the given array around the picked pivot.
There are many different versions of quickSort that pick pivot in different ways.

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
The key process in quickSort is partition().
Target of partitions is, given an array and an element x of array as pivot,
put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
and put all greater elements (greater than x) after x.
All this should be done in linear time.
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

int Partition(int * arr, int left, int right)
{
    int pivot = right;

    int curIndex = left;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < arr[pivot])
        {
            Swap(&arr[curIndex], &arr[i]);
            curIndex++;
        }
    }

    Swap(&arr[curIndex], &arr[pivot]);
    return curIndex;
}

void QuickSort(int * arr, int left, int right)
{
    if (left < right)
    {
        int P = Partition(arr, left, right);
        QuickSort(arr, left, P - 1);
        QuickSort(arr, P + 1, right);
    }
}

void QuickSort(int * arr, int n)
{
    QuickSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = { 1, 5, 2, 3, 7, 4, 9 };
    int n = sizeof(arr) / sizeof(int);

    PrintArray(arr, n);
    QuickSort(arr, n);
    PrintArray(arr, n);

    return 0;
}