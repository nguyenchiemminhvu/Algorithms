#include "BSTree.h"

int main()
{
    BSTree<int> tree;

    tree.Insert(10);
    tree.Insert(4);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(19);
    tree.Insert(15);
    tree.Insert(21);

    tree.PrintPreOrder();
    std::cout << std::endl;

    tree.PrintInOrder();
    std::cout << std::endl;

    tree.PrintPostOrder();
    std::cout << std::endl;

    tree.PrintLevelOrder();
    std::cout << std::endl;

    tree.PrintHeightLevelOrder();
    std::cout << std::endl;

    if (tree.Max())
    {
        std::cout << "Max: " << tree.Max()->data << std::endl;
    }

    if (tree.Min())
    {
        std::cout << "Min: " << tree.Min()->data << std::endl;
    }

    std::cout << "Min distance between two nodes (3, 19): " << tree.MinDistance(3, 19) << std::endl;

    BSTreeNode<int> * pFind = tree.Find(3);
    if (pFind)
    {
        std::cout << "Found " << pFind->data << std::endl;
    }

    BSTreeNode<int> * pCloset = tree.GetCloset(16);
    if (pCloset)
    {
        std::cout << "Closet: " << pCloset->data << std::endl;
    }

    tree.Delete(3);
    tree.PrintHeightLevelOrder();
    std::cout << std::endl;

    tree.PrintVerticalOrder();
    std::cout << std::endl;

    return 0;
}