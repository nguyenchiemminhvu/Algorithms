#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode
{
public:
    TrieNode()
        : isLeaf(false)
    {

    }

    ~TrieNode()
    {

    }

public:

    TrieNode * child_nodes[ALPHABET_SIZE];
    bool isLeaf;
};

class Trie
{
public:
    Trie()
    {
        root = CreateNode();
    }

    ~Trie()
    {

    }

    bool IsEmpty()
    {
        return root == NULL;
    }

    void Insert(std::string key)
    {
        root = InsertUtil(root, key);
    }

    bool Search(std::string key)
    {
        return SearchUtil(root, key);
    }

    void Delete(std::string key)
    {
        root = DeleteUtil(root, key);
    }

    void Clear()
    {
        root = ClearUtil(root);
    }

    void Print()
    {
        PrintUtil(root);
    }

protected:

    TrieNode * CreateNode()
    {
        TrieNode * node = new TrieNode();
        
        node->isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            node->child_nodes[i] = NULL;
        }

        return node;
    }

    TrieNode * InsertUtil(TrieNode * root, std::string key)
    {
        return NULL;
    }

    bool SearchUtil(TrieNode * root, std::string key)
    {
        return false;
    }

    TrieNode * DeleteUtil(TrieNode * root, std::string key)
    {
        return NULL;
    }

    TrieNode * ClearUtil(TrieNode * root)
    {
        return NULL;
    }

    void PrintUtil(TrieNode * root)
    {
        
    }

protected:

    TrieNode * root;
};

#endif // __TRIE_H__