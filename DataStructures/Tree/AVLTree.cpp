#include "Tree.h"

int main()
{
    BSTree<int> tree;

    tree.Insert(1);
    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(7);
    tree.Insert(6);

    tree.PrintHeightLevelOrder();
    std::cout << std::endl;

    return 0;
}