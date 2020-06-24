/*
Counting sort is a sorting technique based on keys between a specific range.
It works by counting the number of objects having distinct key values (kind of hashing).
Then doing some arithmetic to calculate the position of each object in the output sequence.

Let us understand it with the help of an example.

For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int FindMax(int * arr, int n)
{
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = std::max(res, arr[i]);
    }
    return res;
}

int FindMin(int * arr, int n)
{
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        res = std::min(res, arr[i]);
    }
    return res;
}

void CountingSort(int * arr, int n)
{
    int MA = FindMax(arr, n);
    int MI = FindMin(arr, n);
    int range = MA - MI + 1;
    
    int * count = new int[range];
    int * output = new int[range];

    if (!count || !output)
    {
        if (count)
            delete [] count;
        if (output)
            delete [] output;
        
        return;
    }

    std::memset(count, 0, range + 1);
    std::memset(output, 0, range + 1);

    for(int i = 0; i < n; i++) 
        count[arr[i] - MI]++; 
          
    for(int i = 1; i < n; i++) 
        count[i] += count[i - 1]; 
    
    for(int i = n - 1; i >= 0; i--) 
    {  
        output[count[arr[i] - MI] - 1] = arr[i];  
        count[arr[i] - MI]--;  
    }
      
    for(int i = 0; i < n; i++) 
        arr[i] = output[i];
    
    if (count)
        delete [] count;
    if (output)
        delete [] output;
}

int main()
{
    int arr[] = { 5, 3, 1, 7, 2, 9, 8, 4, 6 };
    int n = sizeof(arr) / sizeof(int);

    PrintArray(arr, n);
    CountingSort(arr, n);
    PrintArray(arr, n);

    return 0;
}