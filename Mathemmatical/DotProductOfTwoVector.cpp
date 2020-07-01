/*
There are two vector A and B and we have to find the dot product of two vector array.

Let we have given two vector A = a1 * i + a2 * j + a3 * k and B = b1 * i + b2 * j + b3 * k.
Where i, j and k are the unit vector along the x, y and z directions.
Then dot product is calculated as dot product = a1 * b1 + a2 * b2 + a3 * b3

Example –

A = 3 * i + 5 * j + 4 * k
B = 2 * i + 7 * j + 5 * k
dot product = 3 * 2 + 5 * 7 + 4 * 5
            = 6 + 35 + 20
            = 61
*/

#include <iostream>
using namespace std;

int DotProduct(int * A, int * B, int n = 3)
{
    int product = 0;

    for (int i = 0; i < n; i++)
    {
        product += (A[i] * B[i]);
    }

    return product;
}

int main()
{
    int A[] = { 3, -5, 4 };
    int B[] = { 2, 6, 5 };

    std::cout << DotProduct(A, B) << std::endl;

    return 0;
}