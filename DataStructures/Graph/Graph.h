#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

class Graph
{
protected:
    int num_vertices;
    std::map<int, std::vector<std::pair<int, int>>> G;

public:
    Graph()
        : num_vertices(0)
    {

    }

    ~Graph()
    {

    }

    void AddEdge(int u, int v, int w = 1)
    {
        num_vertices = std::max(num_vertices, std::max(u, v) + 1);
        
        G[u].push_back(std::pair<int, int>(v, w));
    }

    int FindMotherVertex()
    {
        std::vector<bool> visited(num_vertices, false);
        
        int last_vertex = 0;
        for (int i = 0; i < num_vertices; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited);
                last_vertex = i;
            }
        }

        std::fill(visited.begin(), visited.end(), false);
        DFS(last_vertex, visited);

        int check = true;
        for (bool b : visited)
        {
            check &= b;
        }

        return check ? last_vertex : -1;
    }

    void BFS(int from)
    {
        if (from < 0 || from >= num_vertices)
            return;
        
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
                if (!visited[v] && p.second)
                {
                    Q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    void DFS(int from)
    {
        if (from < 0 || from >= num_vertices)
            return;
        
        std::vector<bool> visited(num_vertices, false);
        DFS(from, visited);
    }

    void IterativeDFS(int from)
    {
        if (from < 0 || from >= num_vertices)
            return;
        
        std::vector<bool> visited(num_vertices, false);

        std::stack<int> S;
        S.push(from);

        while (!S.empty())
        {
            int u = S.top();
            S.pop();

            if (!visited[u])
            {
                std::cout << u << " ";
                visited[u] = true;
            }

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && w)
                {
                    S.push(v);
                }
            }
        }
    }

    int CountAllPossiblePaths(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return;
        
        
    }

private:

    void DFS(int from, std::vector<bool> &visited)
    {
        if (from < 0 || from >= num_vertices)
            return;
        
        std::cout << from << " ";
        visited[from] = true;
        for (std::pair<int, int> p : G[from])
        {
            int v = p.first;
            if (!visited[v] && p.second)
            {
                DFS(v, visited);
            }
        }
    }
};

#endif // __GRAPH_H__