#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <limits.h>

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

    int GetNumVertices()
    {
        return num_vertices;
    }

    void AddEdge(int u, int v, int w = 1)
    {
        num_vertices = std::max(num_vertices, std::max(u, v) + 1);
        
        G[u].push_back(std::pair<int, int>(v, w));
    }

    std::vector<std::vector<int>> ConvertToMatrix()
    {
        std::vector<std::vector<int>> res(num_vertices, std::vector<int>(num_vertices, 0));
        for (int u = 0; u < num_vertices; u++)
        {
            for (const std::pair<int, int> &p : G[u])
            {
                int v = p.first;
                int w = p.second;
                res[u][v] = w;
            }
        }

        return res;
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

    bool HasCycle()
    {
        for (int i = 0; i < num_vertices; i++)
        {
            std::vector<bool> visited(num_vertices, false);
            if (IsCyclicUtil(i, visited))
                return true;
        }
        return false;
    }

    int CountAllPossiblePaths(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return 0;
        
        std::vector<bool> visited(num_vertices, false);
        return CountAllPossiblePathsUtil(from, to, visited);
    }

    int MinEdgePath(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return 0;
        
        std::queue<int> Q;

        std::vector<int> dist(num_vertices, 0);
        std::vector<bool> visited(num_vertices, false);
        Q.push(from);

        while (!Q.empty())
        {
            int u = Q.front();
            visited[u] = true;
            Q.pop();

            if (u == to)
                break;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;
                if (!visited[v] && w)
                {
                    Q.push(v);
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                }
            }
        }

        return dist[to];
    }

    int CountNodesInDistance(int from, int dist)
    {
        std::vector<bool> visited(num_vertices, false);
        BFSWithDistance(from, dist, visited);

        int count = 0;
        for (bool b : visited)
        {
            count += (int)b;
        }
        return count;
    }

    int CountTriangles()
    {
        int res = 0;

        for (int u = 0; u < num_vertices; u++)
        {
            for (const std::pair<int, int> &p1 : G[u])
            {
                int v1 = p1.first;
                int w1 = p1.second;
                for (const std::pair<int, int> &p2 : G[v1])
                {
                    int v2 = p2.first;
                    int w2 = p2.second;
                    for (const std::pair<int, int> &p3 : G[v2])
                    {
                        int v3 = p3.first;
                        int w3 = p3.second;
                        if (v3 == u)
                        {
                            res++;
                        }
                    }
                }
            }
        }

        return res / 3;
    }

    void PrintAllPathDFS(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return;
        
        std::vector<bool> visited(num_vertices, false);
        std::vector<int> path;

        PrintAllPathDFSUtil(from, to, visited, path);
    }

    void PrintAllPathBFS(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return;
        
        std::queue<std::vector<int>> QPath;

        std::vector<bool> visited(num_vertices, false);
        std::vector<int> path;
        path.push_back(from);
        visited[from] = true;

        QPath.push(path);

        while (!QPath.empty())
        {
            path = QPath.front();
            QPath.pop();

            int last = path.back();
            if (path.back() == to)
            {
                for (int v : path)
                    std::cout << v << " ";
                std::cout << std::endl;
            }

            for (std::pair<int, int> p : G[last])
            {
                int v = p.first;
                int w = p.second;
                if (!visited[v] && w)
                {
                    std::vector<int> newPath(path.begin(), path.end());
                    newPath.push_back(v);
                    QPath.push(newPath);
                }
            }
        }
    }

    void BuildLevelOfEachNode(int from)
    {
        if (from < 0 || from >= num_vertices)
            return;
        
        std::vector<int> levels(num_vertices, 0);
        std::vector<bool> visited(num_vertices, false);

        std::queue<int> Q;
        Q.push(from);
        levels[from] = 0;
        visited[from] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            visited[u] = true;
            Q.pop();

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && w)
                {
                    Q.push(v);
                    levels[v] = levels[u] + 1;
                }
            }
        }

        for (int i = 0; i < num_vertices; i++)
        {
            std::cout << i << " " << levels[i] << std::endl;
        }
    }

    std::vector<int> ShortestDistanceAllVertices(int from)
    {
        if (from < 0 || from >= num_vertices)
            return {};
        
        std::vector<int> dist(num_vertices, INT_MAX);
        dist[from] = 0;

        std::vector<bool> visited(num_vertices, false);

        for (int count = 0; count < num_vertices; count++)
        {
            int u = DijsktraNextVertex(dist, visited);
            visited[u] = true;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;
                if (!visited[v] && w && dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        return dist;
    }

    int ShortestDistance(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return 0;
        
        std::vector<int> dist(num_vertices, INT_MAX);
        dist[from] = 0;

        std::vector<bool> visited(num_vertices, false);

        for (int count = 0; count < num_vertices; count++)
        {
            int u = DijsktraNextVertex(dist, visited);
            visited[u] = true;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && dist[u] != INT_MAX && w && dist[u] + w <= dist[v])
                {
                    dist[v] = dist[u] + w;
                }

                if (visited[to])
                {
                    return dist[to];
                }
            }
        }

        return INT_MAX;
    }

    void ShortestPath(int from, int to)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return;
        
        std::vector<int> dist(num_vertices, INT_MAX);
        dist[from] = 0;

        std::vector<bool> visited(num_vertices, false);
        std::vector<int> parents(num_vertices, -1);

        for (int count = 0; count < num_vertices; count++)
        {
            int u = DijsktraNextVertex(dist, visited);
            visited[u] = true;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && w && dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parents[v] = u;
                }
            }
        }

        std::stack<int> S;
        int temp = to;
        while (parents[temp] != -1)
        {
            S.push(temp);
            temp = parents[temp];
        }
        
        // if there is a path, add node "from"
        if (!S.empty())
        {
            S.push(from);
        }

        while (!S.empty())
        {
            int node = S.top();
            S.pop();

            std::cout << node << (node != to ? " -> " : "");
        }
        std::cout << std::endl;
    }

    void MinimumSpanningTree()
    {
        std::vector<int> dist(num_vertices, INT_MAX);
        dist[0] = 0;

        std::vector<bool> visited(num_vertices, false);
        std::vector<int> parents(num_vertices, -1);

        for (int count = 0; count < num_vertices; count++)
        {
            int u = DijsktraNextVertex(dist, visited);
            visited[u] = true;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && w && dist[u] != INT_MAX && dist[u] + w <= dist[v])
                {
                    dist[v] = dist[u] + w;
                    parents[v] = u;
                }
            }
        }

        for (int i = 1; i < num_vertices; i++)
        {
            std::cout << parents[i] << " - " << i << std::endl;
        }
    }

    std::vector<int> ColoringAllVertices()
    {
        std::vector<int> res(num_vertices, -1);
        res[0] = 0;

        std::vector<bool> available(num_vertices, true);

        for (int u = 1; u < num_vertices; u++)
        {
            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;
                if (res[v] != -1)
                    available[res[v]] = false;
            }

            int color_code = 0;
            for (color_code = 0; color_code < num_vertices; color_code++)
            {
                if (available[color_code])
                {
                    break;
                }
            }
            res[u] = color_code;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                int w = p.second;
                if (res[v] != -1)
                    available[res[v]] = true;
            }
        }

        return res;
    }

    void HamiltonianCycle()
    {
        std::vector<int> path;
        path.push_back(0);

        std::vector<bool> visited(num_vertices, false);
        visited[0] = true;

        if (FindHamiltonianCycle(1, path, visited))
        {
            for (int u = 0; u < num_vertices; u++)
            {
                std::cout << path[u] << " ";
            }
            std::cout << std::endl;
        }
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

    void BFSWithDistance(int from, int dist, std::vector<bool> &visited)
    {
        if (from < 0 || from >= num_vertices)
            return;

        std::queue<int> Q;
        Q.push(from);
        visited[from] = true;

        int curLevel = 1;
        int nextLevel = 0;

        while (!Q.empty() && dist)
        {
            int u = Q.front();
            Q.pop();
            curLevel--;

            for (std::pair<int, int> p : G[u])
            {
                int v = p.first;
                if (!visited[v] && p.second)
                {
                    Q.push(v);
                    visited[v] = true;
                    nextLevel++;
                }
            }

            if (curLevel == 0)
            {
                curLevel = nextLevel;
                nextLevel = 0;
                dist--;
            }
        }
    }

    bool IsCyclicUtil(int from, std::vector<bool> &visited)
    {
        if (from < 0 || from >= num_vertices)
            return false;
        
        visited[from] = true;
        for (std::pair<int, int> p : G[from])
        {
            int v = p.first;
            int w = p.second;
            if (visited[v])
            {
                return true;
            }
            else if (!visited[v] && w)
            {
                return IsCyclicUtil(v, visited);
            }
        }

        return false;
    }

    int CountAllPossiblePathsUtil(int from, int to, std::vector<bool> &visited)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return 0;
        
        if (from == to)
            return 1;

        int count = 0;
        for (std::pair<int, int> p : G[from])
        {
            int v = p.first;
            int w = p.second;

            if (!visited[v] && w)
            {
                visited[v] = true;
                count += CountAllPossiblePathsUtil(v, to, visited);
                visited[v] = false;
            }
        }

        return count;
    }

    void PrintAllPathDFSUtil(int from, int to, std::vector<bool> &visited, std::vector<int> &path)
    {
        if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices)
            return;
        
        visited[from] = true;
        path.push_back(from);

        if (from == to)
        {
            for (int v : path)
            {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            for (std::pair<int, int> p : G[from])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && w)
                {
                    PrintAllPathDFSUtil(v, to, visited, path);
                }
            }
        }

        path.pop_back();
        visited[from] = false;
    }

    int DijsktraNextVertex(const std::vector<int> &dist, const std::vector<bool> &visited)
    {
        int minDist = INT_MAX;
        int minIdx = -1;

        for (int u = 0; u < num_vertices; u++)
        {
            if (!visited[u] && dist[u] <= minDist)
            {
                minDist = dist[u];
                minIdx = u;
            }
        }

        return minIdx;
    }

    bool FindHamiltonianCycle(int from, std::vector<int> &path, std::vector<bool> &visited)
    {
        return false;
    }
};

#endif // __GRAPH_H__