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
        InsertUtil(root, key);
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
        std::string temp;
        PrintUtil(root, temp);
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

    void InsertUtil(TrieNode * root, std::string key)
    {
        TrieNode * p = root;

        for (char c : key)
        {
            int index = c - 'a';
            if (!p->child_nodes[index])
                p->child_nodes[index] = CreateNode();
            
            p = p->child_nodes[index];
        }

        p->isLeaf = true;
    }

    bool SearchUtil(TrieNode * root, std::string key)
    {
        return false;
    }

    TrieNode * DeleteUtil(TrieNode * root, std::string key)
    {
        return root;
    }

    TrieNode * ClearUtil(TrieNode * root)
    {
        return root;
    }

    void PrintUtil(TrieNode * root, std::string &temp)
    {
        if (!root)
            return;
        
        if (root->isLeaf)
        {
            std::cout << temp << std::endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->child_nodes[i])
            {
                temp += ('a' + i);
                PrintUtil(root->child_nodes[i], temp);
                temp.pop_back();
            }
        }
    }

protected:

    TrieNode * root;
};

#endif // __TRIE_H__