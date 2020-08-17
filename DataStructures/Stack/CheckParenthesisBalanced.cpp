/*
https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced

Input: exp = “[(])”
Output: Not Balanced

Algorithm:

Declare a character stack S.
Now traverse the expression string exp.
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
After complete traversal, if there is some starting bracket left in stack then “not balanced”
*/

#include "Stack.h"
#include <iostream>
using namespace std;

bool IsParenthesisBalanced(std::string ex)
{
    Stack<char> S;
    for (char c : ex)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            S.Push(c);
        }
        else
        {
            if (S.IsEmpty())
                return false;
            
            char check = S.Top();
            S.Pop();

            if (c == ')' && check != '(')
                return false;
            else if (c == ']' && check != '[')
                return false;
            else if (c == '}' && check != '{')
                return false;
        }
    }

    return S.IsEmpty();
}

int main()
{
    std::string ex = "{()}[]";

    if (IsParenthesisBalanced(ex))
        std::cout << "Balanced" << std::endl;
    else
        std::cout << "Not balanced" << std::endl;

    return 0;
}