#ifndef __OPEN_ADDRESSING_HASH_H__
#define __OPEN_ADDRESSING_HASH_H__

#include <vector>
#include <iostream>

template <typename T>
class OAHash
{
public:
    OAHash(int b)
        : BUCKET(b)
    {
        table.resize(b);
    }

    ~OAHash()
    {

    }

    int Hash(T value)
    {
        return 0;
    }

    void Insert(T value)
    {

    }

    bool Search(T value)
    {
        return false;
    }

    void Delete(T value)
    {

    }

    void Print()
    {

    }

private:

    int BUCKET;
    typename std::vector<std::vector<T>> table;
};

#endif // __OPEN_ADDRESSING_HASH_H__