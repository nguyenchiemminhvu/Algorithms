/*
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

void HeapSort(int * arr, int n)
{

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