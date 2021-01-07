#include "Graph.h"

int main()
{
    Graph ug(5);
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 3);
    ug.AddEdge(1, 2);
    ug.AddEdge(2, 3);
    ug.AddEdge(3, 4);
    ug.AddEdge(4, 0);

    ug.BFS(0);

    return 0;
}