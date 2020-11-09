#ifndef __OPEN_ADDRESSING_HASH_H__
#define __OPEN_ADDRESSING_HASH_H__

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

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
        FindPRIME();

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

    int Hash2(int k)
    {
        return (PRIME - (k % PRIME));
    }

    void Insert(int k, T v)
    {
        if (isFull())
        {
            capacity *= 2;
            table.resize(capacity);
            FindPRIME();
        }
        
        OAHashNode<T> *temp = new OAHashNode<T>(k, v);
        InsertUtil(k, temp, cType);
    }

    OAHashNode<T> * Get(int k)
    {
        int index = Hash(k);

        while (table[index])
        {
            int count = 0;
            if (count++ > capacity)
                return NULL;

            if (table[index]->key == k)
            {
                return table[index];
            }

            index = ReHash(index, cType);
        }

        return NULL;
    }

    void Delete(int k)
    {
        int index = Hash(k);

        while (table[index])
        {
            if (table[index]->key == k)
            {
                table[index] = dummy;
                size--;
            }

            index = ReHash(index, cType);
        }
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

    void InsertUtil(int k, OAHashNode<T> * node, CollisionHandleType type)
    {
        switch (type)
        {
        case CollisionHandleType::LINEAR:
            InsertHash(k, node);
            break;
        
        case CollisionHandleType::DOUBLE:
            InsertDoubleHash(k, node);
            break;

        case CollisionHandleType::QUADRATIC:
            InsertQuadraticHash(k, node);
            break;
        
        default:
            break;
        }
    }

    void InsertHash(int k, OAHashNode<T> * node)
    {
        int index = Hash(k);
        while (table[index] && table[index]->key != k && table[index]->key != -1)
        {
            index = ReHash(index, cType);
        }

        if (table[index] == NULL || table[index]->key == -1)
        {
            size++;
            table[index] = node;
        }
    }

    void InsertDoubleHash(int k, OAHashNode<T> * node)
    {
        int index = Hash(k);
        
        if (!table[index] || (table[index] && table[index]->key != -1))
        {
            int index2 = Hash2(k);

            for (int i = 1; ; i++)
            {
                int newIndex = (index + i * index2) % capacity;
                if (!table[newIndex] || (table[newIndex] && table[newIndex]->key == -1))
                {
                    table[newIndex] = node;
                    size++;
                    break;
                }
            }
        }
        else
        {
            table[index] = node;
        }
    }

    void InsertQuadraticHash(int k, OAHashNode<T> * node)
    {
        int index = Hash(k);

    }

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

    void FindPRIME()
    {
        int cur = capacity - 1;
        while (!IsPrime(cur))
        {
            cur--;
        }

        PRIME = cur;
    }

    bool IsPrime(int n)
    {
        int t = sqrt(n);
        for (int i = 2; i <= t; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }

private:

    int capacity;
    int size;
    int PRIME;
    CollisionHandleType cType;
    std::vector<OAHashNode<T> *> table;
    OAHashNode<T> * dummy;
};

#endif // __OPEN_ADDRESSING_HASH_H__