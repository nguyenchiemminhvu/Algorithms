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

    return 0;
}