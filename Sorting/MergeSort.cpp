/*
Merge Sort is a Divide and Conquer algorithm.
It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
See following C implementation for details.

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
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

void Merge(int * arr, int left, int mid, int right)
{
    int * arrLeft = new int[mid - left + 1];
    int * arrRight = new int[right - mid];
    if (!arrLeft || !arrRight)
    {
        if (arrLeft)
            delete [] arrLeft;
        if (arrRight)
            delete [] arrRight;
        
        return;
    }

    int arrIndex = left;
    for (int i = 0; i < mid - left + 1; i++)
        arrLeft[i] = arr[arrIndex++];
    for (int i = 0; i < right - mid; i++)
        arrRight[i] = arr[arrIndex++];
    
    arrIndex = left;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < mid - left + 1 && rightIndex < right - mid)
    {
        if (arrLeft[leftIndex] <= arrRight[rightIndex])
        {
            arr[arrIndex] = arrLeft[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[arrIndex] = arrRight[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }

    while (leftIndex < mid - left + 1)
    {
        arr[arrIndex] = arrLeft[leftIndex];
        leftIndex++;
        arrIndex++;
    }

    while (rightIndex < right - mid)
    {
        arr[arrIndex] = arrRight[rightIndex];
        rightIndex++;
        arrIndex++;
    }

    if (arrLeft)
        delete [] arrLeft;
    if (arrRight)
        delete [] arrRight;
}

void MergeSort(int * arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void MergeSort(int * arr, int n)
{
    MergeSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = { 1, 5, 2, 3, 7, 4, 9 };
    int n = sizeof(arr) / sizeof(int);

    PrintArray(arr, n);
    MergeSort(arr, n);
    PrintArray(arr, n);

    return 0;
}