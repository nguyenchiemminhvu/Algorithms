#include <iostream>
using namespace std;

int LinearSearch(int *arr, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(int);
    cout << LinearSearch(arr, n, 4) << endl;

    return 0;
}