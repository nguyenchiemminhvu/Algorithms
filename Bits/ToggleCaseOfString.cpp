/*
https://www.geeksforgeeks.org/toggle-case-string-using-bitwise-operators/

Given a string, write a function that returns toggle case of a string using the bitwise operators in place.

In ASCII codes, character ‘A’ is integer 65 = (0100 0001)2, while character ‘a’ is integer 97 = (0110 0001)2. Similarly, character ‘D’ is integer 68 = (0100 0100)2, while character ‘d’ is integer 100 = (0110 0100)2.

As we can see, only sixth least significant bit is different in ASCII code of ‘A’ and ‘a’. Similar behavior can be seen in ASCII code of ‘D’ and ‘d’. Therefore, we need to toggle this bit for toggling case.

Examples:

Input : "GeekSfOrgEEKs"
Output : "gEEKsFoRGeekS"                  

Input : "StRinG"
Output : "sTrINg"

The integer with 6th LSB as 1 is 32 (0010 0000). Therefore, bitwise XORing of a character with 32 will toggle the 6th LSB of character and hence, will toggle its case. If character is upper case, it will be converted to lower case and vice versa.
*/

#include <iostream>
#include <string.h>
using namespace std;

void ToggleCase(char * s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        s[i] = s[i] ^ 32;
    }
}

int main()
{
    char s[] = "NguyenChiemMinhVu";

    ToggleCase(s);
    std::cout << s << std::endl;

    return 0;
}