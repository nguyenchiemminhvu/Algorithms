#include "Tree.h"

int main()
{
    AVLTree<int> tree;

    tree.Insert(10);
    tree.Insert(4);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(19);
    tree.Insert(15);
    tree.Insert(21);

    tree.PrintLevelOrder();
    std::cout << std::endl;

    return 0;
}