#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#include <vector>
using namespace std;

class DisjointSet
{
    std::vector<int> parents;
    std::vector<int> size;

public:
    
    DisjointSet(int n)
    {
        parents.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            size[i] = 1;
        }
    }

    ~DisjointSet()
    {

    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        
        if (x != y)
        {
            if (size[x] < size[y])
            {
                std::swap(x, y);
            }
            
            parents[y] = x;
            size[x] += size[y];
        }
    }

    int Find(int i)
    {
        int temp = i;
        while (parents[temp] != temp)
            temp = parents[temp];
        
        parents[i] = temp;
        return temp;
    }
};

#endif // __DISJOINT_SET_H__