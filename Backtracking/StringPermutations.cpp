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

void SolveStringPermutationsProblem(const std::string &input, int left, int right, std::vector<std::string> &res)
{

}

int main()
{
    std::string input = "ABC";

    std::vector<std::string> res;
    SolveStringPermutationsProblem(input, 0, input.length() - 1, res);
    PrintSolution(res);

    return 0;
}