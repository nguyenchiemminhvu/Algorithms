/*
There are two vector A and B and we have to find the cross product of two vector array.

Let we have given two vector A = a1 * i + a2 * j + a3 * k and B = b1 * i + b2 * j + b3 * k.
Then cross product is calculated as cross product = (a2 * b3 – a3 * b2) * i + (a3 * b1 – a1 * b3) * j + (a1 * b2 – a2 * b1) * k,
where [(a2 * b3 – a3 * b2), (a3 * b1 – a1 * b3), (a1 * b2 – a2 * b1)] are the coefficient of unit vector along i, j and k directions.

Example –

A = 3 * i + 5 * j + 4 * k
B = 2 * i + 7 * j + 5 * k
cross product 
= (5 * 5 - 4 * 7) * i + (4 * 2 - 3 * 5) * j + (3 * 7 - 5 * 2) * k
= (-3)*i + (-7)*j + (11)*k
*/

#include <iostream>
using namespace std;

void CrossProduct(int * A, int * B, int * C, int n = 3)
{
    C[0] = A[1] * B[2] - A[2] * B[1];
    C[1] = A[2] * B[0] - A[0] * B[2];
    C[2] = A[0] * B[1] - A[1] * B[0];
}

int main()
{
    int A[] = { 3, -5, 4 };
    int B[] = { 2, 6, 5 };

    int C[] = { 0, 0, 0 };
    CrossProduct(A, B, C);
    for (int i = 0; i < 3; i++)
        std::cout << C[i] << " ";
    std::cout << endl;

    return 0;
}