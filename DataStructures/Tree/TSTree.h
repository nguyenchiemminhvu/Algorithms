#ifndef __TERNARY_SEARCH_TREE_H__
#define __TERNARY_SEARCH_TREE_H__

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
        : isLeaf(false), left(NULL), mid(NULL), right(NULL)
    {

    }

    TSTreeNode(char d)
        : data(d), isLeaf(false), left(NULL), mid(NULL), right(NULL)
    {

    }

    ~TSTreeNode()
    {

    }

public:

    char data;
    bool isLeaf;

    TSTreeNode * left;
    TSTreeNode * mid; // equal
    TSTreeNode * right;

};

class TSTree
{
public:

    TSTree()
    {

    }

    ~TSTree()
    {

    }

    void Insert(std::string word)
    {

    }

    void Print()
    {

    }

protected:

    TSTreeNode * InsertUtil(TSTreeNode * root, std::string word)
    {
        return NULL;
    }

    void PrintUtil(TSTreeNode * root)
    {
        
    }

protected:

    TSTreeNode * root;

};

#endif // __TERNARY_SEARCH_TREE_H__