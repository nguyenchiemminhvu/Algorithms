#ifndef __TRIE_H__
#define __TRIE_H__

#define ALPHABET_SIZE 26

template <typename T>
class TrieNode
{
public:
    TrieNode()
        : isWord(false)
    {

    }

    ~TrieNode()
    {

    }

public:

    TrieNode * children[ALPHABET_SIZE];
    bool isWord;
};

#endif // __TRIE_H__