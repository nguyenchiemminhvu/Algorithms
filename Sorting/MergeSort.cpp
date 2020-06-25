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

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Merge(int * arr, int left, int mid, int right)
{

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