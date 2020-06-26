/*
Write a program to print all permutations of a given string
A permutation, also called an “arrangement number” or “order,”
is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself.
A string of length n has n! permutation.
Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintSolution(const std::vector<std::string> &res)
{
    std::cout << std::endl;
    for (std::string s : res)
    {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
}

void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void SolveStringPermutationsProblem(std::string input, int left, int right, std::vector<std::string> &res)
{
    if (left == right)
    {
        res.push_back(input);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            Swap(&input[left], &input[i]);
            SolveStringPermutationsProblem(input, left + 1, right, res);
            Swap(&input[left], &input[i]);
        }
    }
}

int main()
{
    std::string input = "ABCD";

    std::vector<std::string> res;
    SolveStringPermutationsProblem(input, 0, input.length() - 1, res);
    PrintSolution(res);

    return 0;
}