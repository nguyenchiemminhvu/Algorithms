#include "TSTree.h"

#include <iostream>
using namespace std;

int main()
{
    TSTree T;
    T.Insert("application");
    T.Insert("apply");
    T.Insert("clause");
    T.Insert("close");
    T.Insert("night");
    T.Insert("nine");
    T.Insert("rest");
    T.Insert("best");

    T.Print();
    std::cout << std::endl;

    if (T.Search("close"))
    {
        std::cout << "Found 'close'" << std::endl;
    }

    T.Delete("nine");
    T.Print();
    std::cout << std::endl;

    return 0;
}