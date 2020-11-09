#include "OpenAddressingHash.h"

int main()
{
    OAHash<std::string> h(7, OAHash<std::string>::CollisionHandleType::DOUBLE);

    h.Insert(0, "abc");
    h.Insert(2, "def");
    h.Insert(4, "ghi");
    h.Insert(2, "ikl");
    h.Insert(3, "init");
    h.Insert(1, "hahaha");

    h.Print();

    std::cout << std::endl;
    if (h.Get(3))
    {
        std::cout << "Found: " << h.Get(3)->value << std::endl;
    }

    std::cout << std::endl;
    h.Delete(3);
    h.Print();

    std::cout << std::endl;
    h.Insert(3, "ncmv");
    h.Print();

    return 0;
}