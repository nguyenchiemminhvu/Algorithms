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
        : root(NULL)
    {
    }

    virtual ~BSTree()
    {
        Clear();
    }

    virtual bool Insert(T value)
    {
        TreeNode<T> * node = CreateNode(value);
        if (!node)
            return false;
        
        root = InsertUtil(root, node);
        return true;
    }

    TreeNode<T> * Find(T value)
    {
        if (!root)
            return NULL;
        
        TreeNode<T> * p = root;
        while (p && p->data != value)
        {
            if (p->data > value)
            {
                p = p->left;
            }
            else 
            {
                p = p->right;
            }
        }

        return p;
    }

    virtual void Delete(T value)
    {
        root = DeleteUtil(root, value);
    }

    void PrintPreOrder()
    {
        PrintPreOrderUtil(root);
    }

    void PrintInOrder()
    {
        PrintInOrderUtil(root);
    }

    void PrintPostOrder()
    {
        PrintPostOrderUtil(root);
    }

    void PrintLevelOrder()
    {
        PrintLevelOrderUtil(root);
    }

    int Size()
    {
        return 0;
    }

    int Height()
    {
        return 0;
    }

    bool IsEmpty()
    {
        return root == NULL;
    }

    void Clear()
    {
        ClearUtil(root);
    }

    TreeNode<T> * Min()
    {
        return GetMinUtil(root);
    }

    TreeNode<T> * Max()
    {
        return GetMaxUtil(root);
    }

protected:

    TreeNode<T> * CreateNode(T v)
    {
        TreeNode<T> * node = new TreeNode<T>(v);
        return node;
    }

    virtual TreeNode<T> * InsertUtil(TreeNode<T> * root, TreeNode<T> * node)
    {
        if (!root)
        {
            return node;
        }

        if (root->data == node->data)
        {
            return root;
        }

        if (root->data > node->data)
        {
            root->left = InsertUtil(root->left, node);
        }
        else if (root->data < node->data)
        {
            root->right = InsertUtil(root->right, node);
        }

        return root;
    }

    virtual TreeNode<T> * DeleteUtil(TreeNode<T> * root, T value)
    {
        if (!root)
            return root;
        
        if (root->data > value)
        {
            root->left = DeleteUtil(root->left, value);
        }
        else if (root->data < value)
        {
            root->right = DeleteUtil(root->right, value);
        }
        else
        {
            if (!root->left)
            {
                TreeNode<T> * temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                TreeNode<T> * temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode<T> * temp = GetMinUtil(root->right);
                root->data = temp->data;
                root->right = DeleteUtil(root->right, temp->data);
            }
        }

        return root;
    }

    void PrintPreOrderUtil(TreeNode<T> * root)
    {
        if (!root)
            return;
        
        std::cout << root->data << " ";
        PrintPreOrderUtil(root->left);
        PrintPreOrderUtil(root->right);
    }

    void PrintInOrderUtil(TreeNode<T> * root)
    {
        if (!root)
            return;

        PrintInOrderUtil(root->left);
        std::cout << root->data << " ";
        PrintInOrderUtil(root->right);
    }

    void PrintPostOrderUtil(TreeNode<T> * root)
    {
        if (!root)
            return;

        PrintPostOrderUtil(root->left);
        PrintPostOrderUtil(root->right);
        std::cout << root->data << " ";
    }

    void PrintLevelOrderUtil(TreeNode<T> * root)
    {
        std::queue<TreeNode<T> *> Q;
        int curLevel = 1, nextLevel = 0;
        Q.push(root);

        while (!Q.empty())
        {
            TreeNode<T> * node = Q.front();
            Q.pop();
            curLevel--;

            std::cout << node->data << " ";

            if (node->left)
            {
                Q.push(node->left);
                nextLevel++;
            }
            if (node->right)
            {
                Q.push(node->right);
                nextLevel++;
            }

            if (curLevel == 0)
            {
                curLevel = nextLevel;
                nextLevel = 0;

                std::cout << std::endl;
            }
        }
    }

    TreeNode<T> * GetMinUtil(TreeNode<T> * root)
    {
        TreeNode<T> * p = root;
        while (p && p->left)
        {
            p = p->left;
        }

        return p;
    }

    TreeNode<T> * GetMaxUtil(TreeNode<T> * root)
    {
        TreeNode<T> * p = root;
        while (p && p->right)
        {
            p = p->right;
        }

        return p;
    }

    void ClearUtil(TreeNode<T> *&root)
    {
        if (!root)
            return;
        
        ClearUtil(root->left);
        ClearUtil(root->right);
        delete root;
        root = NULL;
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

    AVLTree(const std::vector<T> &v)
    {

    }

    virtual ~AVLTree()
    {
        
    }

protected:

};

#endif // __BINARY_SEARCH_TREE_H__