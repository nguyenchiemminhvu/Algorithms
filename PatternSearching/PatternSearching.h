#ifndef __PATTERN_SEARCHING_H__
#define __PATTERN_SEARCHING_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PatternSearching
{
public:
    PatternSearching()
    {

    }

    ~PatternSearching()
    {

    }

    std::vector<size_t> NaiveSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        for (int i = 0; i <= text.length() - pattern.length(); i++)
        {
            int j;
            for (j = 0; j < pattern.length(); j++)
            {
                if (pattern[j] != text[i + j])
                    break;
            }

            if (j == pattern.length())
            {
                res.push_back(i);
            }
        }

        return res;
    }

    std::vector<size_t> KMPSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        return res;
    }

    std::vector<size_t> FiniteAutomataSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        return res;
    }

    std::vector<size_t> BMA_BadCharacterSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        return res;
    }

    std::vector<size_t> BMA_GoodSuffixSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        return res;
    }
};

#endif // __PATTERN_SEARCHING_H__