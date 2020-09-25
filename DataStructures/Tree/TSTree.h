#ifndef __TERNARY_SEARCH_TREE_H__
#define __TERNARY_SEARCH_TREE_H__

#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

class TSTreeNode
{
public:
    TSTreeNode()
        : isLeaf(false), isRoot(false), left(NULL), mid(NULL), right(NULL)
    {
    }

    TSTreeNode(char d)
        : data(d), isLeaf(false), isRoot(false), left(NULL), mid(NULL), right(NULL)
    {
    }

    ~TSTreeNode()
    {

    }

public:

    char data;
    bool isLeaf;
    bool isRoot;

    TSTreeNode * left;
    TSTreeNode * mid; // equal pointer
    TSTreeNode * right;
};

class TSTree
{
public:

    TSTree()
        : root(NULL)
    {

    }

    ~TSTree()
    {

    }

    bool IsEmpty()
    {
        return !root;
    }

    bool Insert(std::string word)
    {
        return false;
    }

    bool Search(std::string word)
    {
        return false;
    }

    void Delete(std::string word)
    {

    }

    void Clear()
    {

    }

    void Print()
    {

    }

protected:

    TSTreeNode * CreateNode(char data)
    {
        TSTreeNode * node = new TSTreeNode(data);
        return node;
    }

    bool HasNoChild(TSTreeNode * root)
    {
        return !root->left && !root->mid && !root->right;
    }

    TSTreeNode * InsertUtil(TSTreeNode * root, std::string word, int depth = 0)
    {
        return NULL;
    }

    bool SearchUtil(TSTreeNode * root, std::string word, int depth = 0)
    {
        return false;
    }

    void DeleteUtil(TSTreeNode * root, std::string word, int depth = 0)
    {

    }

    void ClearUtil(TSTreeNode * root)
    {

    }

    void PrintUtil(TSTreeNode * root)
    {

    }

protected:

    TSTreeNode * root;

};

#endif // __TERNARY_SEARCH_TREE_H__