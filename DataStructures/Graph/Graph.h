#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>

class Graph
{
protected:
    int num_vertices;
    std::map<int, std::vector<std::pair<int, int>>> G;

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
        std::vector<bool> visited(num_vertices, false);

        std::queue<int> Q;
        Q.push(from);
        visited[from] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            std::cout << u << " ";
            Q.pop();

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                if (!visited[v])
                {
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    void DFS(int from)
    {
        std::vector<bool> visited(num_vertices, false);
        DFS(from, visited);
    }

private:

    void DFS(int from, std::vector<bool> &visited)
    {
        std::cout << from << " ";
        visited[from] = true;
        for (std::pair<int, int> p : G[from])
        {
            int v = p.first;
            if (!visited[v])
            {
                DFS(v, visited);
            }
        }
    }
};

#endif // __GRAPH_H__