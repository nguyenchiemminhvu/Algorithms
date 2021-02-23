#include "Graph.h"

int main()
{
    Graph ug(true);
    ug.AddEdge(0, 1, 7);
    ug.AddEdge(0, 3, 5);
    ug.AddEdge(1, 2, 8);
    ug.AddEdge(1, 3, 9);
    ug.AddEdge(1, 4, 7);
    ug.AddEdge(2, 4, 5);
    ug.AddEdge(3, 4, 15);
    ug.AddEdge(3, 5, 6);
    ug.AddEdge(4, 5, 8);
    ug.AddEdge(4, 6, 9);
    ug.AddEdge(5, 6, 11);

    ug.MinimumSpanningTree_Prim();
    std::cout << std::endl;
    ug.MinimumSpanningTree_Kruskals();

    return 0;
}