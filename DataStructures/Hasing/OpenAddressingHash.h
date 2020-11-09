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
        return GetUtil(k, cType);
    }

    void Delete(int k)
    {
        DeleteUtil(k, cType);
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
            index++;
            index %= capacity;
        }

        if (table[index] == NULL || table[index]->key == -1)
        {
            size++;
        }
        
        table[index] = node;
    }

    void InsertDoubleHash(int k, OAHashNode<T> * node)
    {
        int index = Hash(k);

        if (table[index] && table[index]->key != -1)
        {
            int index2 = Hash2(k);
            for (int i = 0; ; i++)
            {
                int newIndex = (index + i * index2) % capacity;
                std::cout << newIndex << std::endl;
                if (!table[newIndex] || table[newIndex]->key == -1)
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
            size++;
        }
    }

    void InsertQuadraticHash(int k, OAHashNode<T> * node)
    {
        int index = Hash(k);

    }

    OAHashNode<T> * GetUtil(int k, CollisionHandleType t)
    {
        switch (t)
        {
        case CollisionHandleType::LINEAR:
            return GetUtilHash(k);
        
        case CollisionHandleType::DOUBLE:
            return GetUtilDouble(k);

        case CollisionHandleType::QUADRATIC:
            return GetUtilQuadratic(k);
        }

        return NULL;
    }

    OAHashNode<T> * GetUtilHash(int k)
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

            index++;
            index %= capacity;
        }

        return NULL;
    }

    OAHashNode<T> * GetUtilDouble(int k)
    {
        OAHashNode<T> * res = NULL;

        int index1 = Hash(k);
        int index2 = Hash2(k);
        int i = 0;
        for ( ; (index1 + i * index2) % capacity != k ; i++)
        {
            if (table[(index1 + i * index2) % capacity]->key == -1)
            {
                return NULL;
            }
        }

        return table[(index1 + i * index2) % capacity];
    }

    OAHashNode<T> * GetUtilQuadratic(int k)
    {
        return NULL;
    }

    void DeleteUtil(int k, CollisionHandleType t)
    {
        switch (t)
        {
        case CollisionHandleType::LINEAR:
            DeleteUtilHash(k);
            break;
        
        case CollisionHandleType::DOUBLE:
            DeleteUtilDouble(k);
            break;

        case CollisionHandleType::QUADRATIC:
            DeleteUtilQuadratic(k);
            break;
        }
    }

    void DeleteUtilHash(int k)
    {
        int index = Hash(k);

        while (table[index])
        {
            if (table[index]->key == k)
            {
                table[index] = dummy;
                size--;
            }

            index++;
            index %= capacity;
        }
    }

    void DeleteUtilDouble(int k)
    {

    }

    void DeleteUtilQuadratic(int k)
    {

    }

    void FindPRIME()
    {
        int cur = capacity - 1;
        while (!IsPrime(cur))
            cur--;
        
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