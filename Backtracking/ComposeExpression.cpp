/*
https://www.geeksforgeeks.org/print-all-possible-expressions-that-evaluate-to-a-target/

Given a string that contains only digits from 0 to 9, and an integer value, target. 
Find out how many expressions are possible which evaluate to target using binary operator +, – and * in given string of digits.

Input : "123",  Target : 6
Output : {“1+2+3”, “1*2*3”}

Input : “125”, Target : 7
Output : {“1*2+5”, “12-5”}

This problem can be solved by putting all possible binary operator in mid between to digits and evaluating them and then check they evaluate to target or not.

While writing the recursive code, we need to keep these variable as argument of recursive method – result vector, input string, current expression string, target value, position till which input is processed, current evaluated value and last value in evaluation.
Last value is kept in recursion because of multiplication operation, while doing multiplication we need last value for correct evaluation.

See below example for better understanding –

Input is 125, suppose we have reached till 1+2 now,
Input = “125”, current expression = “1+2”, 
position = 2, current val = 3, last = 2

Now when we go for multiplication, we need last 
value for evaluation as follows:

current val = current val - last + last * current val

First we subtract last and then add last * current 
val for evaluation, new last is last * current val.
current val = 3 – 2 + 2*5 = 11
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ComposeExpression(
    std::string digits, 
    int target, 
    int pos,
    int curValue,
    int lastValue,
    std::string curExp,
    std::vector<std::string> &allExp)
{
    if (pos == digits.length())
    {
        if (curValue == target)
            allExp.push_back(curExp);
        
        return;
    }

    for (int i = pos; i < digits.length(); i++)
    {
        std::string sub = digits.substr(pos, i - pos + 1);
        int subValue = std::atoi(sub.c_str());

        // If pos is 0, just send the subValue to next recursion
        if (pos == 0)
        {
            ComposeExpression(digits, target, i + 1, subValue, subValue, curExp + sub, allExp);
        }
        // Try all given binary operators for evaluation
        else
        {
            ComposeExpression(digits, target, i + 1, curValue + subValue, curValue, curExp + "+" + sub, allExp);
            ComposeExpression(digits, target, i + 1, curValue - subValue, -curValue, curExp + "-" + sub, allExp);
            ComposeExpression(digits, target, i + 1, curValue * subValue, curValue - lastValue + lastValue * curValue, curExp + "*" + sub, allExp);
        }    
    }
}

int main()
{
    std::string digits = "125";
    int target = 7;

    std::string curExp;
    std::vector<std::string> allExp;
    ComposeExpression(digits, target, 0, 0, 0, curExp, allExp);

    for (std::string s : allExp)
    {
        std::cout << s << std::endl;
    }

    return 0;
}