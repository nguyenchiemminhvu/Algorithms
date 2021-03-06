#ifndef __PATTERN_SEARCHING_H__
#define __PATTERN_SEARCHING_H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    std::vector<size_t> BMA_BadCharacterSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        std::vector<int> BadChars(256, -1);
        BMA_BuildBadCharacters(pattern, BadChars);

        int i = 0;
        while (i <= (text.length() -  pattern.length()))
        {
            int j = pattern.length() - 1;
            while (j >= 0 && text[i + j] == pattern[j])
            {
                j--;
            }

            if (j < 0)
            {
                res.push_back(i);
                if (i + pattern.length() < text.length())
                    i += pattern.length() - BadChars[text[i + pattern.length()]];
                else
                    i++;
            }
            else
            {
                i += std::max(1, j - BadChars[text[i + j]]);
            }
            
        }

        return res;
    }

    std::vector<size_t> BMA_GoodSuffixSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;
        
        std::vector<int> GoodSuffix(pattern.length() + 1, 0);
        std::vector<int> bpos = BMA_BuildFullGoodSuffix(pattern, GoodSuffix);
        BMA_BuildPartialGoodSuffix(pattern, bpos, GoodSuffix);

        int i = 0;
        int j = 0;
        while (i <= (text.length() - pattern.length()))
        {
            j = pattern.length() - 1;
            while (j >= 0 && pattern[j] == text[i + j])
                j--;
            
            if (j < 0)
            {
                res.push_back(i);
                i += GoodSuffix[0];
            }
            else
            {
                i += GoodSuffix[j + 1];
            }
            
        }

        return res;
    }

    std::vector<size_t> STLSearch(std::string text, std::string pattern)
    {
        std::vector<size_t> res;

        size_t found = text.find(pattern);
        while (found != std::string::npos)
        {
            res.push_back(found);
            found = text.find(pattern, found + 1);
        }

        return res;
    }

    void CheckPalindromeStream(const std::string &s)
    {
        if (s.empty())
            return;
        
        std::cout << "YES" << std::endl;
        if (s.length() == 1)
            return;
        
        int prime = 103;
        int TOTAL_CHARS = 256;

        int HashLeft = s[0] % prime;
        int HashRight = s[1] % prime;
        int H = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (HashLeft == HashRight)
            {
                int j;
                for (j = 0; j < i / 2; j++)
                {
                    if (s[j] != s[i - j])
                    {
                        break;
                    }
                }
                if (j == i / 2)
                    std::cout << "YES" << std::endl;
                else
                    std::cout << "NO" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }

            // Calculate Hash value for the next iteration
            if (i != s.length() - 1)
            {
                if (i & 1)
                {
                    HashRight = TOTAL_CHARS * (HashRight + prime - s[(i + 1) / 2] * H) % prime + s[i + 1] % prime;
                }
                else
                {
                    H = (H * TOTAL_CHARS) % prime;
                    HashLeft = (HashLeft + H * s[i / 2]) % prime;
                    HashRight = (HashRight * TOTAL_CHARS + s[i + 1]) % prime;                    
                }
            }
        }
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

    void BMA_BuildBadCharacters(std::string pattern, std::vector<int> &BadChars)
    {
        for (int i = 0; i < pattern.length(); i++)
        {
            BadChars[pattern[i]] = i;
        }
    }

    std::vector<int> BMA_BuildFullGoodSuffix(std::string pattern, std::vector<int> &GoodSuffix)
    {
        std::vector<int> bpos(pattern.length() + 1, 0);
        bpos[pattern.length()] = pattern.length() + 1;

        int i = pattern.length();
        int j = pattern.length() + 1;

        while (i > 0)
        {
            while (j <= pattern.length() && pattern[i - 1] != pattern[j - 1])
            {
                if (GoodSuffix[j] == 0)
                {
                    GoodSuffix[j] = j - i;
                }
                j = bpos[j];
            }

            i--;
            j--;
            bpos[i] = j;
        }

        return bpos;
    }

    void BMA_BuildPartialGoodSuffix(std::string pattern, const std::vector<int> &bpos, std::vector<int> &GoodSuffix)
    {
        int j = bpos[0];
        for (int i = 0; i <= pattern.length(); i++)
        {
            if (GoodSuffix[i] == 0)
            {
                GoodSuffix[i] = j;
            }
            
            if (i == j)
                j = bpos[j];
        }
    }
};

#endif // __PATTERN_SEARCHING_H__