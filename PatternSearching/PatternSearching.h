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

        std::vector<int> match;
        KMP_BuildMatchTable(pattern, match);

        int i = 0;
        int j = 0;
        while (i < text.length())
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if (j == pattern.length())
            {
                res.push_back(i - j);
                j = match[j - 1];
            }
            
            if (i < text.length() && text[i] != pattern[j])
            {
                if (j != 0)
                {
                    j = match[j - 1];
                }
                else
                {
                    i++;
                }
                
            }
        }

        return res;
    }

    std::vector<size_t> RabinKarpSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        int TOTAL_CHARS = 256;
        int prime = 101;

        int hashT = 0;
        int hashP = 0;
        int H = 1;

        for (int i = 0; i < pattern.length() - 1; i++)
        {
            H = (H * TOTAL_CHARS) % prime;
        }

        for (int i = 0; i < pattern.length(); i++)
        {
            hashP = (hashP * TOTAL_CHARS + pattern[i]) % prime;
            hashT = (hashT * TOTAL_CHARS + text[i]) % prime;
        }

        for (int i = 0; i < text.length() - pattern.length(); i++)
        {
            if (hashP == hashT)
            {
                int j = 0;
                for (j = 0; j < pattern.length(); j++)
                {
                    if (text[j] != pattern[j])
                        break;
                }

                if (j == pattern.length())
                {
                    res.push_back(i);
                }
            }

            if (i < text.length() - pattern.length())
            {
                hashT = (TOTAL_CHARS * (hashT - text[i] * H) + text[i + pattern.length()]) % prime;
                if (hashT < 0)
                {
                    hashT += prime;
                }
            }
        }

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

private:

    void KMP_BuildMatchTable(std::string pattern, std::vector<int> &match)
    {
        match.clear();
        match.resize(pattern.length());
        std::fill(match.begin(), match.end(), 0);

        int i = 1;
        int len = 0;
        while (i < match.size())
        {
            if (pattern[i] != pattern[len])
            {
                if (len != 0)
                {
                    len = match[i - 1];
                }
                else
                {
                    match[i] = 0;
                    i++;
                }
                
            }
            else
            {
                i++;
                len++;
                match[i] = len;
            }
            
        }
    }
};

#endif // __PATTERN_SEARCHING_H__