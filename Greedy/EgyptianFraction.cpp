/*
https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/

Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.

Following are few examples:

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

We can generate Egyptian Fractions using Greedy Algorithm. 
For a given number of the form ‘nr/dr’ where dr > nr, 
first find the greatest possible unit fraction, 
then recur for the remaining part. 
For example, consider 6/14, we first find ceiling of 14/6, i.e., 3.
So the first unit fraction becomes 1/3, then recur for (6/14 – 1/3) i.e., 4/42.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Fraction
{
    int _numerator;
    int _denominator;

    Fraction(int n = 0, int d = 0)
        : _numerator(n), _denominator(d)
    {

    }

    void GenerateEgyptianFraction(std::vector<Fraction> &res)
    {
        
    }

    std::string Str()
    {
        return std::to_string(_numerator) + "/" + std::to_string(_denominator);
    }
};

int main()
{
    Fraction F(6, 14);

    std::vector<Fraction> egyptianFraction;
    F.GenerateEgyptianFraction(egyptianFraction);

    for (int i = 0; i < egyptianFraction.size(); i++)
    {
        std::cout << egyptianFraction[i].Str();
        if (i < egyptianFraction.size() - 1)
        {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;

    return 0;
}