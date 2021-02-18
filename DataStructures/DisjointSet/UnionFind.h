#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

#include <vector>
using namespace std;

class UnionFind
{
    std::vector<std::pair<int, int>> parents;

public:
    
    UnionFind(int n)
    {
        parents.resize(n);
        std::fill(parents.begin(), parents.end(), std::pair<int, int>(-1, 0));
    }

    ~UnionFind()
    {

    }

    void Union(int x, int y)
    {

    }

    int Find(int i)
    {
        return -1;
    }
};

#endif