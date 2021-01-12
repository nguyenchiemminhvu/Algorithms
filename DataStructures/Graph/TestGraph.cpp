#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(0, 3);
    ug.AddEdge(1, 3);
    ug.AddEdge(2, 0);
    ug.AddEdge(2, 1);
    
    ug.PrintAllPathDFS(2, 3);

    return 0;
}