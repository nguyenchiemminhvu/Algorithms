#include "TSTree.h"
#include <iostream>
using namespace std;

int main()
{
    TSTree T;
    
    T.Insert("application");
    T.Insert("apart");
    T.Insert("apartment");
    T.Insert("apply");
    T.Insert("attention");
    T.Insert("attribute");
    T.Insert("basic");
    T.Insert("bound");
    T.Insert("best");

    T.Print();
    std::cout << std::endl;

    T.Clear();

    T.Print();
    std::cout << std::endl;

    return 0;
}