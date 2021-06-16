#include "UniquePointer.h"
#include "SharedPointer.h"

#include <iostream>
#include <memory>

int main()
{
    int *temp = new int(10);

    UniquePointer<int> u1(temp);
    std::unique_ptr<int> u2(temp);

    std::cout << *u1 << std::endl;
    std::cout << *u2 << std::endl;

    SharedPointer<int> p1(temp);
    SharedPointer<int> p2(p1);
    
    std::shared_ptr<int> s1(temp);
    std::shared_ptr<int> s2(s1);

    std::cout << p1.ref_count() << std::endl;
    std::cout << p2.ref_count() << std::endl;
    std::cout << s1.use_count() << std::endl;
    std::cout << s1.use_count() << std::endl;

    return 0;
}