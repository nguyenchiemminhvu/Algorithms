/*
https://www.geeksforgeeks.org/postfix-to-infix/

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Postfix notation, also known as reverse Polish notation, is a syntax for mathematical expressions in which the mathematical operator is always placed after the operands. Though postfix expressions are easily and efficiently evaluated by computers, they can be difficult for humans to read. Complex expressions using standard parenthesized infix notation are often more readable than the corresponding postfix expressions. Consequently, we would sometimes like to allow end users to work with infix notation and then convert it to postfix notation for computer processing. Sometimes, moreover, expressions are stored or generated in postfix, and we would like to convert them to infix for the purpose of reading and editing

Examples:

Input : abc++
Output : (a + (b + c))

Input  : ab*c+
Output : ((a*b)+c)

Algorithm
1.While there are input symbol left
…1.1 Read the next symbol from the input.
2.If the symbol is an operand
…2.1 Push it onto the stack.
3.Otherwise,
…3.1 the symbol is an operator.
…3.2 Pop the top 2 values from the stack.
…3.3 Put the operator, with the values as arguments and form a string.
…3.4 Push the resulted string back to stack.
4.If there is only one value in the stack
…4.1 That value in the stack is the desired infix string.
*/

#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

bool IsOperand(char c)
{
    return c >= 'a' && c <= 'z';
}

std::string PostfixToInfix(std::string ex)
{
    Stack<std::string> S;
    for (char c : ex)
    {
        if (IsOperand(c))
        {
            std::string op(1, c);
            S.Push(op);
        }
        else
        {
            std::string op1 = S.Top();
            S.Pop();
            std::string op2 = S.Top();
            S.Pop();

            S.Push("(" + op2 + c + op1 + ")"); 
        }
    }

    return S.Top();
}

int main()
{
    std::string ex = "abcd*e-*fgh*+*+i-";
    std::cout << PostfixToInfix(ex) << std::endl;

    return 0;
}