#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <list>
#include <map>

class Graph
{
protected:
    int num_vertices;
    std::map<int, std::vector<std::pair<int, int>> G;

public:
    Graph(int n)
        : num_vertices(n)
    {

    }

    ~Graph()
    {

    }

    void AddEdge(int u, int v, int w = 1)
    {
        if (u < 0 || u >= num_vertices || v < 0 || v >= num_vertices)
            return;
        
        G[u].push_back(std::pair<int, int>(v, w));
    }

    void BFS(int from)
    {

    }

    void DFS(int from)
    {

    }
};

#endif // __GRAPH_H__