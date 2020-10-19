#ifndef __CHAIN_HASH_H__
#define __CHAIN_HASH_H__

#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename T>
class ChainHash
{
public:
    ChainHash(int b)
        : BUCKET(b)
    {
        table.resize(b);
    }

    ~ChainHash()
    {
    }

    int Hash(T value)
    {
        return (int)value % BUCKET;
    }

    bool Search(T value)
    {
        int index = Hash(value);
        
        typename std::list<T>::iterator iter;
        for (iter = table[index].begin(); iter != table[index].end(); iter++)
        {
            if (*iter == value)
                break;
        }

        if (iter != table[index].end())
            return true;
        
        return false;
    }

    void Insert(T value)
    {
        int index = Hash(value);
        table[index].push_back(value);
    }

    void Delete(T value)
    {
        int index = Hash(value);

        typename std::list<T>::iterator iter;
        for (iter = table[index].begin(); iter != table[index].end(); iter++)
        {
            if (*iter == value)
            {
                break;
            }
        }

        if (iter != table[index].end())
        {
            table[index].erase(iter);
        }
    }

    void Print()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            std::cout << i << ": ";
            for (T v : table[i])
            {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

private:

    int BUCKET;
    typename std::vector<std::list<T>> table;

};

#endif // __CHAIN_HASH_H__