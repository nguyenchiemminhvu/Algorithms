#include <iostream>
using namespace std;

int BinarySearch(int *arr, int n, int value)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == value)
            return mid;
        
        if (value > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(int);
    cout << BinarySearch(arr, n, 4) << endl;

    return 0;
}