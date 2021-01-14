#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(0, 4);
    ug.AddEdge(1, 0);
    ug.AddEdge(1, 2);
    ug.AddEdge(2, 0);
    ug.AddEdge(2, 1);
    ug.AddEdge(2, 5);
    ug.AddEdge(3, 4);
    ug.AddEdge(4, 0);
    ug.AddEdge(4, 3);
    ug.AddEdge(4, 5);
    ug.AddEdge(4, 6);
    ug.AddEdge(5, 2);
    ug.AddEdge(5, 4);
    ug.AddEdge(6, 4);
    
    std::cout << ug.MinEdgePath(1, 5) << std::endl;

    return 0;
}