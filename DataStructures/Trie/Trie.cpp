#include "Trie.h"

int main()
{
    Trie T;
    T.Insert("cash");
    T.Insert("card");
    T.Insert("last");
    T.Insert("part");
    T.Insert("count");
    T.Insert("program");
    T.Insert("application");

    if (T.Search("program"))
    {
        std::cout << "Found: program" << std::endl;
    }
    

    T.Print();
    std::cout << std::endl;

    T.Delete("count");
    T.Delete("application");
    T.Delete("program");

    T.Print();
    std::cout << std::endl;

    T.Insert("hello");

    T.Print();
    std::cout << std::endl;

    return 0;
}