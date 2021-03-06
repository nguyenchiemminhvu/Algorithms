#include "ChainHash.h"
#include <iostream>
using namespace std;

int main()
{
    ChainHash<int> h(10);
    h.Insert(11);
    h.Insert(34);
    h.Insert(43);
    h.Insert(45);
    h.Insert(25);
    h.Insert(7);
    h.Insert(66);
    h.Insert(11);
    h.Insert(10);
    h.Insert(79);
    h.Insert(8);
    h.Insert(7);

    h.Print();

    if (h.Search(54))
    {
        std::cout << "Found" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    
    ChainHash<std::string> hh(255);
    hh.Insert("abc");
    hh.Insert("def");
    hh.Insert("ghi");
    hh.Insert("klm");
    hh.Insert("empty");
    hh.Insert("element");
    hh.Insert("anniversary");
    
    hh.Print();
    
    return 0;
}