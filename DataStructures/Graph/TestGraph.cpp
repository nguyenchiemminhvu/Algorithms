#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 3);
    ug.AddEdge(0, 8);
    ug.AddEdge(1, 0);
    ug.AddEdge(2, 3);
    ug.AddEdge(3, 0);
    ug.AddEdge(3, 2);
    ug.AddEdge(3, 5);
    ug.AddEdge(3, 6);
    ug.AddEdge(3, 7);
    ug.AddEdge(4, 5);
    ug.AddEdge(5, 3);
    ug.AddEdge(5, 4);
    ug.AddEdge(5, 9);
    ug.AddEdge(6, 3);
    ug.AddEdge(7, 3);
    ug.AddEdge(8, 0);
    ug.AddEdge(9, 5);
    
    std::cout << ug.CountNodesInDistance(0, 2) << std::endl;

    return 0;
}