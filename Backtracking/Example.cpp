#include <iostream>
using namespace std;

void Func(int n)
{
    if (n == 0)
        return;

    Func(n - 1);
    cout << n << endl;
}

int main()
{
    Func(10);
    return 0;
}