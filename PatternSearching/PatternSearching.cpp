#include "PatternSearching.h"

using namespace std;

int main()
{
    std::string text = "AABAACAADAABAAABAA";
    std::string pattern = "AABA";

    PatternSearching PS;
    std::vector<size_t> res;

    res = PS.NaiveSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    res = PS.KMPSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    res = PS.RabinKarpSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    res = PS.BMA_BadCharacterSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    res = PS.BMA_GoodSuffixSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    res = PS.STLSearch(text, pattern);
    for (int idx : res)
    {
        std::cout << "found at index: " << idx << std::endl;
    }

    PS.CheckPalindromeStream("aabaacaabaa");

    return 0;
}