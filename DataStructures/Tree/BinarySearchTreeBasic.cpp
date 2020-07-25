#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node * left;
    Node * right;
};

Node * NewNode(int data)
{
    Node * n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node * AddNode(Node * root, int data)
{
    if (root == NULL)
    {
        root = NewNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = AddNode(root->left, data);
        }
        else
        {
            root->right = AddNode(root->right, data);
        }
    }
    
    return root;
}

void LevelOrderTraversal(Node * root)
{
    std::queue<Node *> Q;
    Q.push(root);

    int curLevel = 1;
    int nextLevel = 0;

    while (!Q.empty())
    {
        Node * n = Q.front();
        Q.pop();
        curLevel--;

        if (n != NULL)
        {
            cout << n->data << " ";
            
            if (n->left != NULL)
            {
                Q.push(n->left);
                nextLevel++;
            }
            
            if (n->right != NULL)
            {
                Q.push(n->right);
                nextLevel++;
            }
        }

        if (curLevel == 0)
        {
            curLevel = nextLevel;
            nextLevel = 0;
            std::cout << std::endl;
        }
    }
}

Node * Search(Node * root, int key)
{
    if (root != NULL && root->data == key)
        return root;

    if (root->left && key < root->data)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

void Release(Node * root)
{
    std::queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node * n = Q.front();
        Q.pop();

        if (n != NULL)
        {
            if (n->left != NULL)
            {
                Q.push(n->left);
            }
            
            if (n->right != NULL)
            {
                Q.push(n->right);
            }

            delete n;
        }
    }

    root = NULL;
}

int main()
{
    Node * root = NULL;
    root = AddNode(root, 50);
    root = AddNode(root, 30);
    root = AddNode(root, 20);
    root = AddNode(root, 70);
    root = AddNode(root, 60);
    root = AddNode(root, 100);
    root = AddNode(root, 10);

    LevelOrderTraversal(root);
    
    if (Search(root, 20))
    {
        std::cout << "Found" << std::endl;
    }
    
    Release(root);
    return 0;
}