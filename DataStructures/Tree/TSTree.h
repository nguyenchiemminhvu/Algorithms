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
    {

    }

    ~TSTreeNode()
    {

    }

public:

    char key;
    bool isLeaf;

    TSTreeNode * left;
    TSTreeNode * mid; // equal
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

    void Insert(std::string word)
    {
        char * s = &word[0];
        root = InsertUtil(root, s);
    }

    void Print()
    {
        char buffer[1024];
        PrintUtil(root, buffer, 0);
    }

    void Clear()
    {
        root = ClearUtil(root);
    }

protected:

    TSTreeNode * InsertUtil(TSTreeNode * root, char * s)
    {
        if (!root)
        {
            root = new TSTreeNode();
            root->key = *s;
            root->isLeaf = false;
            root->left = root->mid = root->right = NULL;
        }

        if (*s < root->key)
        {
            root->left = InsertUtil(root->left, s);
        }
        else if (*s > root->key)
        {
            root->right = InsertUtil(root->right, s);
        }
        else
        {
            if (*(s + 1))
            {
                root->mid = InsertUtil(root->mid, s + 1);
            }
            else
            {
                root->isLeaf = true;
            }
        }

        return root;
    }

    void PrintUtil(TSTreeNode * root, char * buffer, int depth)
    {
        if (root)
        {
            PrintUtil(root->left, buffer, depth);
            
            buffer[depth] = root->key;
            if (root->isLeaf)
            {
                buffer[depth + 1] = '\0';
                std::cout << buffer << std::endl;
            }

            PrintUtil(root->mid, buffer, depth + 1);
            PrintUtil(root->right, buffer, depth);
        }
    }

    TSTreeNode * ClearUtil(TSTreeNode * root)
    {
        if (!root)
            return NULL;
        
        ClearUtil(root->left);
        ClearUtil(root->mid);
        ClearUtil(root->right);

        delete root;
        root = NULL;

        return root;
    }

protected:

    TSTreeNode * root;

};

#endif // __TERNARY_SEARCH_TREE_H__