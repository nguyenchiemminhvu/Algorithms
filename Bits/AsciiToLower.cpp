/*
Logic: The bit representation of upper case and lower case English alphabets are –




A -> 01000001          a -> 01100001
B -> 01000010          b -> 01100010
C -> 01000011          c -> 01100011
  .                               .
  .                               .
Z -> 01011010          z -> 01111010
As we can see if we set 5th bit of upper case characters, it will be converted into lower case character. We have to prepare a mask having 5th bit 1 and other 0 (00100000). This mask is bit representation of space character (‘ ‘). The character ‘ch’ then ORed with mask.

Example-
ch = ‘A’ (01000001)
mask = ‘ ‘ (00100000)
ch | mask = ‘a’ (01100001)
*/

#include <iostream>
using namespace std;

char ToLower(char ch)
{
    return ch | ' ';
}

int main()
{
    char upperCh = 'A';
    char lowerCh = ToLower(upperCh);
    std::cout << lowerCh << std::endl;
    
    return 0;
}