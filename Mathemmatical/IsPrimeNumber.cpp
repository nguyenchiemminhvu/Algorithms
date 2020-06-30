/*
https://www.geeksforgeeks.org/prime-numbers/

A prime number is a whole number greater than 1, which is only divisible by 1 and itself. 
First few prime numbers are : 2 3 5 7 11 13 17 19 23 …..

Some interesting fact about Prime numbers

Two is the only even Prime number.

Every prime number can represented in form of 6n+1 or 6n-1 except 2 and 3, where n is natural number.

Two and Three are only two consecutive natural numbers which are prime too.

Goldbach Conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.

Wilson Theorem : Wilson’s theorem states that a natural number p > 1 is a prime number if and only if
    (p - 1) ! ≡  -1   mod p 
OR  (p - 1) ! ≡  (p-1) mod p

Fermat’s Little Theorem: If n is a prime number, then for every a, 1 <= a < n,
an-1 ≡ 1 (mod n)
 OR 
an-1 % n = 1 

Prime Number Theorem : The probability that a given,
randomly chosen number n is prime is inversely proportional to its number of digits,
or to the logarithm of n.

Lemoine’s Conjecture : Any odd integer greater than 5 can be expressed as a sum of an odd prime
(all primes other than 2 are odd) and an even semiprime.
A semiprime number is a product of two prime numbers.
This is called Lemoine’s conjecture.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
    if (n < 2)
        return false;
    
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n = 7;

    if (IsPrime(n))
    {
        std::cout << "A prime number" << std::endl;
    }
    else
    {
        std::cout << "Not a prime number" << std::endl;
    }
    
    return 0;
}