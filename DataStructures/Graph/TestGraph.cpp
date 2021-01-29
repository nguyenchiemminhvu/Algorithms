#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 3);
    ug.AddEdge(1, 0);
    ug.AddEdge(1, 2);
    ug.AddEdge(1, 3);
    ug.AddEdge(1, 4);
    ug.AddEdge(2, 1);
    ug.AddEdge(2, 4);
    ug.AddEdge(3, 0);
    ug.AddEdge(3, 1);
    ug.AddEdge(3, 4);
    ug.AddEdge(4, 1);
    ug.AddEdge(4, 2);
    ug.AddEdge(4, 3);

    ug.HamiltonianCycle();

    return 0;
}