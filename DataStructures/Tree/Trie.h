#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
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
        : isRoot(false), isLeaf(false)
    {

    }

    ~TrieNode()
    {

    }

public:

    TrieNode * child_nodes[ALPHABET_SIZE];
    bool isRoot;
    bool isLeaf;
};

class Trie
{
public:
    Trie()
    {
        root = CreateNode();
        root->isRoot = true;
    }

    ~Trie()
    {
        Clear();
        
        if (root)
        {
            delete root;
            root = NULL;
        }
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

    std::vector<std::string> GetAllCompletion(std::string prefix)
    {
        std::vector<std::string> completion;
        GetAllCompletionUtil(root, prefix, completion);
        return completion;
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
        if (!root)
            return;
        
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
        if (!root)
            return false;
        
        TrieNode * p = root;
        
        for (char c : key)
        {
            int index = (c - 'a');
            if (!p->child_nodes[index])
                return false;
            
            p = p->child_nodes[index];
        }

        return p && p->isLeaf;
    }

    TrieNode * DeleteUtil(TrieNode * root, std::string key, int depth = 0)
    {
        if (!root)
            return NULL;
        
        if (depth == key.length())
        {
            if (root->isLeaf)
                root->isLeaf = false;
            
            if (HasNoChild(root))
            {
                delete root;
                root = NULL;
            }

            return root;
        }

        int index = key[depth] - 'a';
        root->child_nodes[index] = DeleteUtil(root->child_nodes[index], key, depth + 1);

        if (HasNoChild(root) && !root->isLeaf && !root->isRoot)
        {
            delete root;
            root = NULL;
        }

        return root;
    }

    TrieNode * ClearUtil(TrieNode * root)
    {
        if (!root)
            return NULL;
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->child_nodes[i])
            {
                root->child_nodes[i] = ClearUtil(root->child_nodes[i]);
            }
        }
        
        if (HasNoChild(root) && !root->isRoot)
        {
            delete root;
            root = NULL;
        }

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

    bool GetAllCompletionUtil(TrieNode * root, std::string prefix, std::vector<std::string> &res)
    {
        if (!root)
            return false;

        TrieNode * p = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (!p->child_nodes[index])
                return false;
            
            p = p->child_nodes[index];
        }
        
        bool isLast = HasNoChild(p);
        if (isLast && p->isLeaf)
        {
            res.push_back(prefix);
            return false;
        }

        if (!isLast)
        {
            std::vector<std::string> postfixes;
            std::string temp;
            GetCompletionPostfixAt(p, postfixes, temp);

            for (std::string postfix : postfixes)
            {
                res.push_back(prefix + postfix);
            }
        }
        
        return true;
    }

    void GetCompletionPostfixAt(TrieNode * root, std::vector<std::string> &res, std::string &temp)
    {
        if (!root)
            return;
        
        if (root->isLeaf)
        {
            res.push_back(temp);
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->child_nodes[i])
            {
                temp += ('a' + i);
                GetCompletionPostfixAt(root->child_nodes[i], res, temp);
                temp.pop_back();
            }
        }
    }

    bool HasNoChild(TrieNode * root)
    {
        if (!root)
            return true;
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (root->child_nodes[i])
                return false;
        }
        return true;
    }

protected:

    TrieNode * root;
};

#endif // __TRIE_H__