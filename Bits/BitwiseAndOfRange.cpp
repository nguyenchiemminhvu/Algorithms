/*
https://www.geeksforgeeks.org/bitwise-and-or-of-a-range/

Given two non-negative long integers, x and y given x <= y, the task is to find bit-wise and of all integers from x and y, i.e., we need to compute value of x & (x+1) & … & (y-1) & y.7

Examples:

Input  : x = 12, y = 15
Output : 12 
12 & 13 & 14 & 15 = 12 

Input  : x = 10, y = 20
Output : 0 

1) Find position of Most Significant Bit (MSB) in both numbers.
2) If positions of MSB are different, then result is 0.
3) If positions are same. Let positions be msb_p.
……a) We add 2msb_p to result.
……b) We subtract 2msb_p from x and y,
……c) Repeat steps 1, 2 and 3 for new values of x and y.

Example 1 :
x = 10, y = 20
Result is initially 0.
Position of MSB in x = 3
Position of MSB in y = 4
Since positions are different, return result.

Example 2 :
x = 17, y = 19
Result is initially 0.
Position of MSB in x = 4
Position of MSB in y = 4
Since positions are same, we compute 24.

We add 24 to result. 
Result becomes 16.

We subtract this value from x and y.
New value of x  = x - 24  = 17 - 16 = 1
New value of y  = y - 24  = 19 - 16 = 3

Position of MSB in new x = 1
Position of MSB in new y = 2
Since positions are different, we return result.

More efficient solution

Flip the LSB of b.
And check if the new number is in range(a < number < b) or not
if the number greater than 'a' again flip lsb
if it is not then that's the answer
*/

#include <iostream>
using namespace std;

int msb_pos(int n)
{
    int pos = -1;
    while (n)
    {
        n >>= 1;
        pos++;
    }
    return pos;
}

int BitwiseAndOfRange(int left, int right)
{
    while (right > left)
    {
        right = (right & (right - 1));
    }

    return right;
}

int main()
{
    int left = 12, right = 15;

    std::cout << BitwiseAndOfRange(left, right) << std::endl;

    return 0;
}