/*
https://www.geeksforgeeks.org/program-nth-catalan-number/

Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

4) Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
*/

#include <iostream>
using namespace std;

unsigned long int NthCatalanNumber(int nth)
{
    if (nth <= 1)
        return 1;
    
    unsigned long int res = 0;
    for (int i = 0; i < nth; i++)
    {
        res += NthCatalanNumber(i) * NthCatalanNumber(nth - i - 1);
    }
    
    return res;
}

int main()
{
    for (int i = 0; i < 10; i++) 
        cout << NthCatalanNumber(i) << " "; 
    return 0;
}