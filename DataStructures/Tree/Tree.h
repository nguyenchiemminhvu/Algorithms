#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    TreeNode()
        : height(1), left(NULL), right(NULL)
    {
    }

    TreeNode(T d)
        : data(d), height(1), left(NULL), right(NULL)
    {
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
            left = NULL;
        }

        if (right)
        {
            delete right;
            right = NULL;
        }
    }

public:

    T data;
    TreeNode<T> * left;
    TreeNode<T> * right;
    int height;
};

template <typename T>
class BSTree
{
public:
    BSTree()
    {

    }

    virtual ~BSTree()
    {
        Clear();
    }

    virtual bool Insert(T value)
    {
        return false;
    }

    TreeNode<T> * Find(T value)
    {
        return NULL;
    }

    virtual bool Delete(T value)
    {
        return false;
    }

    void PrintPreOrder()
    {

    }

    void PrintInOrder()
    {

    }

    void PrintPostOrder()
    {

    }

    void PrintLevelOrder()
    {

    }

    int Size()
    {
        return 0;
    }

    int Height()
    {
        return 0;
    }

    void Clear()
    {

    }

protected:

    TreeNode<T> * root;
};

template <typename T>
class AVLTree : public BSTree<T>
{
public:
    AVLTree()
    {
        
    }

    virtual ~AVLTree()
    {
        
    }

protected:

};

#endif // __BINARY_SEARCH_TREE_H__