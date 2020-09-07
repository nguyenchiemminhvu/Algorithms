#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    TreeNode()
        : left(NULL), right(NULL)
    {
    }

    TreeNode(T d)
        : data(d), left(NULL), right(NULL)
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
    
};

template <typename T>
class BSTree
{
public:
    BSTree()
    {

    }

    ~BSTree()
    {
        Clear();
    }

    bool Insert(T value)
    {
        return false;
    }

    TreeNode<T> * Find(T value)
    {
        return NULL;
    }

    bool Delete(T value)
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

    int Size()
    {
        return 0;
    }

    void Clear()
    {

    }

private:

    TreeNode<T> * root;
};

#endif // __BINARY_SEARCH_TREE_H__