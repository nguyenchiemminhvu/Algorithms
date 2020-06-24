/*
    The selection sort algorithm sorts an array
    by repeatedly finding the minimum element (considering ascending order)
    from unsorted part and putting it at the beginning.
    The algorithm maintains two subarrays in a given array.

    1) The subarray which is already sorted.
    2) Remaining subarray which is unsorted.

    In every iteration of selection sort,
    the minimum element (considering ascending order) 
    from the unsorted subarray is picked and moved to the sorted subarray.
*/

#include <iostream>
using namespace std;

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *arr, int n)
{
    int minIndex = 0;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }

        Swap(&arr[minIndex], &arr[i]);
    }
}

int main()
{
    int arr[] = { 1, 5, 2, 3, 7, 4, 9 };
    int n = sizeof(arr) / sizeof(int);

    PrintArray(arr, n);
    SelectionSort(arr, n);
    PrintArray(arr, n);

    return 0;
}