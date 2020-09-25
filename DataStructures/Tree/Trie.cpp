#include "Trie.h"

#include <vector>
#include <string>
using namespace std;

int main()
{
    Trie T;
    T.Insert("cash");
    T.Insert("card");
    T.Insert("captive");
    T.Insert("capital");
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

    T.Delete("cash");
    T.Delete("card");
    T.Delete("part");
    T.Delete("application");

    T.Print();
    std::cout << std::endl;

    T.Insert("password");
    T.Insert("part");
    T.Insert("party");
    T.Insert("partition");
    T.Insert("particular");
    T.Insert("partner");
    T.Insert("parent");
    T.Insert("parallel");
    T.Insert("patient");
    T.Insert("passive");

    T.Print();
    std::cout << std::endl;

    std::vector<std::string> ss = T.GetAllCompletion("part");
    for (std::string s : ss)
    {
        std::cout << s << std::endl;
    }

    T.Clear();

    return 0;
}