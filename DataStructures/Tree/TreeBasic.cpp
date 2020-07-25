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

void InOrderTraversal(Node * root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        std::cout << root->data << " ";
        InOrderTraversal(root->right);
    }
}

void PreOrderTraversal(Node * root)
{
    if (root != NULL)
    {
        std::cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(Node * root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
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

int main()
{
    Node * root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->right->left = NewNode(5);
    root->right->right = NewNode(6);

    InOrderTraversal(root);
    std::cout << std::endl;

    PreOrderTraversal(root);
    std::cout << std::endl;

    PostOrderTraversal(root);
    std::cout << std::endl;

    LevelOrderTraversal(root);
    std::cout << std::endl;


    return 0;
}