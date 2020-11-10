#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class BSTreeNode
{
public:
    BSTreeNode()
        : height(1), count(1), left(NULL), right(NULL)
    {
    }

    BSTreeNode(T d)
        : data(d), height(1), count(1), left(NULL), right(NULL)
    {
    }

    ~BSTreeNode()
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
    BSTreeNode<T> * left;
    BSTreeNode<T> * right;
    int height;
    int count;
};

template <typename T>
class BSTree
{
public:
    BSTree()
        : root(NULL)
    {
    }

    BSTree(std::vector<T> v)
        : root(NULL)
    {
        std::sort(v.begin(), v.end());
        root = BuildTreeFromSortedArray(v, 0, v.size() - 1);
    }

    virtual ~BSTree()
    {
        Clear();
    }

    virtual bool Insert(T value)
    {
        BSTreeNode<T> * node = CreateNode(value);
        if (!node)
            return false;
        
        root = InsertUtil(root, node);
        return true;
    }

    BSTreeNode<T> * Find(T value)
    {
        if (!root)
            return NULL;
        
        BSTreeNode<T> * p = root;
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

    BSTreeNode<T> * GetCloset(T value)
    {
        int minDiff = INT_MAX;
        BSTreeNode<T> * closet = NULL;
        
        GetClosetUtil(root, value, minDiff, closet);

        return closet;
    }

    int MinDistance(T value1, T value2)
    {
        BSTreeNode<T> * p1 = Find(value1);
        BSTreeNode<T> * p2 = Find(value2);

        if (!p1 || !p2)
            return -1;
        
        if (value1 == value2)
            return 0;
        
        if (value2 < value1)
            std::swap(value1, value2);
        
        return MinDistanceUtil(root, value1, value2);
    }

    virtual void Delete(T value)
    {
        root = DeleteUtil(root, value);
    }

    void RemoveAllLeaf()
    {
        root = RemoveAllLeafUtil(root);
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

    void PrintHeightLevelOrder()
    {
        PrintHeightLevelOrderUtil(root);
    }

    void PrintVerticalOrder()
    {
        PrintVerticalOrderUtil(root);
    }

    int Size()
    {
        return GetSizeUtil(root);
    }

    int Height()
    {
        return GetHeightUtil(root);
    }

    int Height(BSTreeNode<T> * node)
    {
        if (!node)
            return 0;
        return node->height;
    }

    int GetBalance(BSTreeNode<T> * node)
    {
        return GetBalanceUtil(node);
    }

    bool IsEmpty()
    {
        return root == NULL;
    }

    void Clear()
    {
        ClearUtil(root);
    }

    BSTreeNode<T> * Min()
    {
        return GetMinUtil(root);
    }

    BSTreeNode<T> * Max()
    {
        return GetMaxUtil(root);
    }

protected:

    virtual BSTreeNode<T> * CreateNode(T v)
    {
        BSTreeNode<T> * node = new BSTreeNode<T>(v);
        return node;
    }

    BSTreeNode<T> * BuildTreeFromSortedArray(const std::vector<T> &v, int start, int end)
    {
        if (start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        BSTreeNode<T> * node = CreateNode(v[mid]);
        node->left = BuildTreeFromSortedArray(v, start, mid - 1);
        node->right = BuildTreeFromSortedArray(v, mid + 1, end);

        return node;
    }

    virtual BSTreeNode<T> * InsertUtil(BSTreeNode<T> * root, BSTreeNode<T> * node)
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
        else
        {
            return root;
        }

        root->height = 1 + std::max(Height(root->left), Height(root->right));

        int balance = GetBalanceUtil(root);

        // left left
        if (balance > 1 && node->data < root->left->data)
        {
            return RightRotateUtil(root);
        }

        // right right
        if (balance < -1 && node->data > root->right->data)
        {
            return LeftRotateUtil(root);
        }

        // left right
        if (balance > 1 && node->data > root->left->data)
        {
            root->left = LeftRotateUtil(root->left);
            return RightRotateUtil(root);
        }
        
        // right left
        if (balance < -1 && node->data < root->right->data)
        {
            root->right = RightRotateUtil(root->right);
            return LeftRotateUtil(root);
        }

        return root;
    }

    virtual BSTreeNode<T> * DeleteUtil(BSTreeNode<T> * root, T value)
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
                BSTreeNode<T> * temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                BSTreeNode<T> * temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                BSTreeNode<T> * temp = GetMinUtil(root->right);
                root->data = temp->data;
                root->right = DeleteUtil(root->right, temp->data);
            }
        }

        if (!root)
            return NULL;

        root->height = 1 + std::max(Height(root->left), Height(root->right));

        int balance = GetBalanceUtil(root);

        // left left
        if (balance > 1 && GetBalanceUtil(root->left) > 0)
        {
            return RightRotateUtil(root);
        }

        // right right
        if (balance < 1 && GetBalanceUtil(root->right) < 0)
        {
            return LeftRotateUtil(root);
        }

        // left right
        if (balance > 1 && GetBalanceUtil(root->left) < 0)
        {
            root->left = LeftRotateUtil(root->left);
            return RightRotateUtil(root);
        }

        // right left
        if (balance < 1 && GetBalanceUtil(root->right) > 0)
        {
            root->right = RightRotateUtil(root->right);
            return LeftRotateUtil(root);
        }

        return root;
    }

    BSTreeNode<T> * RemoveAllLeafUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return NULL;
        
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        root->left = RemoveAllLeafUtil(root->left);
        root->right = RemoveAllLeafUtil(root->right);

        return root;
    }

    void PrintPreOrderUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return;
        
        std::cout << root->data << " ";
        PrintPreOrderUtil(root->left);
        PrintPreOrderUtil(root->right);
    }

    void PrintInOrderUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return;

        PrintInOrderUtil(root->left);
        std::cout << root->data << " ";
        PrintInOrderUtil(root->right);
    }

    void PrintPostOrderUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return;

        PrintPostOrderUtil(root->left);
        PrintPostOrderUtil(root->right);
        std::cout << root->data << " ";
    }

    void PrintLevelOrderUtil(BSTreeNode<T> * root)
    {
        std::queue<BSTreeNode<T> *> Q;
        int curLevel = 1, nextLevel = 0;
        Q.push(root);

        while (!Q.empty())
        {
            BSTreeNode<T> * node = Q.front();
            Q.pop();
            curLevel--;

            std::cout << node->data << " ";
            
            if (!node)
            {
                continue;
            }
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

    void PrintHeightLevelOrderUtil(BSTreeNode<T> * root)
    {
        std::queue<BSTreeNode<T> *> Q;
        int curLevel = 1, nextLevel = 0;
        Q.push(root);

        while (!Q.empty())
        {
            BSTreeNode<T> * node = Q.front();
            Q.pop();
            curLevel--;

            std::cout << node->data << "(" << node->height <<") ";

            if (!node)
            {
                continue;
            }
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

    void PrintVerticalOrderUtil(BSTreeNode<T> * root)
    {
    }

    BSTreeNode<T> * GetMinUtil(BSTreeNode<T> * root)
    {
        BSTreeNode<T> * p = root;
        while (p && p->left)
        {
            p = p->left;
        }

        return p;
    }

    BSTreeNode<T> * GetMaxUtil(BSTreeNode<T> * root)
    {
        BSTreeNode<T> * p = root;
        while (p && p->right)
        {
            p = p->right;
        }

        return p;
    }

    void GetClosetUtil(BSTreeNode<T> * root, T value, int &minDiff, BSTreeNode<T> *&closet)
    {
        if (!root)
            return;
        
        if (root->data == value)
        {
            closet = root;
            return;
        }

        int curDiff = abs(root->data - value);
        if (minDiff > curDiff)
        {
            minDiff = curDiff;
            closet = root;
        }

        if (value < root->data)
        {
            GetClosetUtil(root->left, value, minDiff, closet);
        }
        else
        {
            GetClosetUtil(root->right, value, minDiff, closet);
        }
    }

    int MinDistanceUtil(BSTreeNode<T> * root, T value1, T value2)
    {
        if (!root)
            return 0;
        
        if (root->data > value1 && root->data > value2)
        {
            return MinDistanceUtil(root->left, value1, value2);
        }
        
        if (root->data < value1 && root->data < value2)
        {
            return MinDistanceUtil(root->right, value1, value2);
        }

        if (root->data >= value1 && root->data <= value2)
        {
            return DistanceFromRoot(root, value1) + DistanceFromRoot(root, value2);
        }

        return 0;
    }

    int DistanceFromRoot(BSTreeNode<T> * root, int value)
    {
        if (root->data == value)
            return 0;
        else if (root->data > value)
            return 1 + DistanceFromRoot(root->left, value);
        else
            return 1 + DistanceFromRoot(root->right, value);
    }

    void ClearUtil(BSTreeNode<T> *&root)
    {
        if (!root)
            return;
        
        ClearUtil(root->left);
        ClearUtil(root->right);
        delete root;
        root = NULL;
    }

    int GetSizeUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return 0;
        
        return 1 + GetSizeUtil(root->left) + GetSizeUtil(root->right);
    }

    int GetHeightUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return 0;
        
        int lh = GetHeightUtil(root->left);
        int rh = GetHeightUtil(root->right);
        return std::max(lh, rh) + 1;
    }

    int GetBalanceUtil(BSTreeNode<T> * root)
    {
        if (!root)
            return 0;
        return (Height(root->left) - Height(root->right));
    }

    BSTreeNode<T> * LeftRotateUtil(BSTreeNode<T> * root)
    {
        BSTreeNode<T> * r = root->right;
        BSTreeNode<T> * rl = r->left;

        r->left = root;
        root->right = rl;

        root->height = std::max(GetHeightUtil(root->left), GetHeightUtil(root->right)) + 1;
        r->height = std::max(GetHeightUtil(r->left), GetHeightUtil(r->right)) + 1;

        return r;
    }

    BSTreeNode<T> * RightRotateUtil(BSTreeNode<T> * root)
    {
        BSTreeNode<T> * l = root->left;
        BSTreeNode<T> * lr = l->right;

        l->right = root;
        root->left = lr;

        root->height = std::max(GetHeightUtil(root->left), GetHeightUtil(root->right)) + 1;
        l->height = std::max(GetHeightUtil(l->left), GetHeightUtil(l->right)) + 1;

        return l;
    }

public:

    BSTreeNode<T> * root;
};

#endif // __BINARY_SEARCH_TREE_H__