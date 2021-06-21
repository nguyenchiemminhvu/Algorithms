#include <iostream>
using namespace std;

int FindMissingNonNeg(int * arr, int n)
{
    bool miss_one = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            miss_one = false;
            break;
        }
    }

    if (miss_one)
        return 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0 || arr[i] >= n)
        {
            arr[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[(arr[i] - 1) % n] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main()
{
    int arr[] = { 0, 1, 4, 3, 2, 8, 7, 5 };
    int n = sizeof(arr) / sizeof(int);

    std::cout << FindMissingNonNeg(arr, n) << std::endl;

    return 0;
}