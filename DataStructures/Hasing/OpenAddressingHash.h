#ifndef __OPEN_ADDRESSING_HASH_H__
#define __OPEN_ADDRESSING_HASH_H__

#include <string>
#include <vector>
#include <iostream>

template <typename T>
class OAHashNode
{
public:
    int key;
    T value;

    OAHashNode()
    {
        key = -1;
    }

    OAHashNode(int k, T v)
        : key(k), value(v)
    {

    }
};

template <typename T>
class OAHash
{
public:
    enum CollisionHandleType
    {
        LINEAR,
        DOUBLE,
        QUADRATIC
    };

public:
    OAHash(int c, CollisionHandleType t = LINEAR)
        : capacity(c), size(0), cType(t)
    {
        table.resize(capacity);
        for (int i = 0; i < capacity; i++)
        {
            table[i] = NULL;
        }

        dummy = new OAHashNode<T>();
    }

    ~OAHash()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i])
                delete table[i];
        }
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int Hash(int k)
    {
        return k % capacity;
    }

    void Insert(int k, T v)
    {
        if (isFull())
        {
            capacity *= 2;
            table.resize(capacity);
        }
        
        OAHashNode<T> *temp = new OAHashNode<T>(k, v);
        
        int index = Hash(k);
        while (table[index] && table[index]->key != k && table[index]->key != -1)
        {
            index = ReHash(index, cType);
        }

        if (table[index] == NULL || table[index]->key == -1)
            size++;
        
        table[index] = temp;
    }

    bool Search(T value)
    {
        return false;
    }

    void Delete(T value)
    {

    }

    T Get(int key)
    {
        return NULL;
    }

    void Print()
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << i << " -> ";
            if (table[i] && table[i]->key != -1)
            {
                std::cout << table[i]->key << ": " << table[i]->value << std::endl;
            }
        }
    }

private:

    int ReHash(int index, CollisionHandleType t)
    {
        switch (t)
        {
        case CollisionHandleType::LINEAR:
            index++;
            index %= capacity;
            break;
        
        case CollisionHandleType::DOUBLE:
            break;

        case CollisionHandleType::QUADRATIC:
            break;
        
        default:
            break;
        }

        return index;
    }

private:

    int capacity;
    int size;
    CollisionHandleType cType;
    std::vector<OAHashNode<T> *> table;
    OAHashNode<T> * dummy;
};

#endif // __OPEN_ADDRESSING_HASH_H__