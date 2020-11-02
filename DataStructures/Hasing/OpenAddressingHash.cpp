#include "OpenAddressingHash.h"

int main()
{
    OAHash<std::string> h(4);

    h.Insert(0, "abc");
    h.Insert(2, "def");
    h.Insert(4, "ghi");
    h.Insert(2, "ikl");
    h.Insert(3, "init");
    h.Insert(1, "hahaha");

    h.Print();

    return 0;
}