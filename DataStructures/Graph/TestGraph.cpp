#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 0);
    ug.AddEdge(1, 3);
    ug.AddEdge(2, 1);
    ug.AddEdge(3, 2);

    std::cout << ug.CountTriangles() << std::endl;

    return 0;
}