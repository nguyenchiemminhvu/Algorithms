#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 3);
    ug.AddEdge(1, 4);
    ug.AddEdge(1, 5);
    ug.AddEdge(2, 6);
    ug.AddEdge(6, 7);
    
    ug.BuildLevelOfEachNode(0);

    return 0;
}