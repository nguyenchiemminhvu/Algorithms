#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 3);
    ug.AddEdge(4, 1);
    ug.AddEdge(6, 4);
    ug.AddEdge(5, 6);
    ug.AddEdge(5, 2);
    ug.AddEdge(6, 0);

    ug.IterativeDFS(5);

    return 0;
}