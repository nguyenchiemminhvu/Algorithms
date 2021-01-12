#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(0, 4);
    ug.AddEdge(1, 3);
    ug.AddEdge(1, 4);
    ug.AddEdge(2, 4);
    ug.AddEdge(3, 2);
    
    std::cout << ug.CountAllPossiblePaths(0, 4) << std::endl;

    return 0;
}