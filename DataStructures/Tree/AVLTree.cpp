#include "Tree.h"

int main()
{
    AVLTree<int> tree;

    tree.Insert(10);
    tree.Insert(4);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(7);
    tree.Insert(6);

    tree.PrintLevelOrder();
    std::cout << std::endl;

    return 0;
}