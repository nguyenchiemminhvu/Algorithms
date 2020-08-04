/*
Logic: The bit representation of upper case and lower case English alphabets are –

A -> 01000001                a -> 01100001
B -> 01000010                b -> 01100010
C -> 01000011                c -> 01100011
.                               .
.                               .
Z -> 01011010                z -> 01111010
As we can see if we clear 5th bit of lower case characters, it will be converted into upper case character. We have to prepare a mask having 5th bit 0 and other 1 (10111111). This mask is bit representation of underscore character (‘_‘). The character ‘ch’ then AND with mask.
Example-
ch = ‘a’ (01100001)
mask = ‘_ ‘ (11011111)
ch & mask = ‘A’ (01000001)
*/

#include <iostream>
using namespace std;

char ToUpper(char ch)
{
    return ch & '_';
}

int main()
{
    char lowerCh = 'a';
    char upperCh = ToUpper(lowerCh);
    std::cout << upperCh << std::endl;

    return 0;
}