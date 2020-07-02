/*
https://www.geeksforgeeks.org/factorial-large-number/

Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n. For example factorial of 6 is 6*5*4*3*2*1 which is 720.

Factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long long int.

Input : 100
Output : 933262154439441526816992388562667004-
         907159682643816214685929638952175999-
         932299156089414639761565182862536979-
         208272237582511852109168640000000000-
         00000000000000

Input :50
Output : 3041409320171337804361260816606476884-
         4377641568960512000000000000
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::string Factorial(int n)
{
    std::string res = "1";
    
    int carry = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            int tmp = (res[j] - '0') * i;
            res[j] = '0' + (tmp + carry) % 10;
            carry = (tmp + carry) / 10;
        }

        while (carry != 0)
        {
            res.push_back('0' + (carry % 10));
            carry = carry / 10;
        }

    }
    
    return std::string(res.rbegin(), res.rend());
}

int main()
{
    std::string F = Factorial(400);
    std::cout << F << std::endl;

    return 0;
}