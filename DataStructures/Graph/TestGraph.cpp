#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1, 10);
    ug.AddEdge(0, 2, 15);
    ug.AddEdge(0, 3, 20);
    ug.AddEdge(1, 0, 10);
    ug.AddEdge(1, 2, 35);
    ug.AddEdge(1, 3, 25);
    ug.AddEdge(2, 0, 15);
    ug.AddEdge(2, 1, 35);
    ug.AddEdge(2, 3, 30);
    ug.AddEdge(3, 0, 20);
    ug.AddEdge(3, 1, 25);
    ug.AddEdge(3, 2, 30);

    return 0;
}