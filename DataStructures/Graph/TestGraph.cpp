#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1, 4);
    ug.AddEdge(0, 7, 8);
    ug.AddEdge(1, 0, 4);
    ug.AddEdge(1, 7, 11);
    ug.AddEdge(1, 2, 8);
    ug.AddEdge(2, 1, 8);
    ug.AddEdge(2, 3, 7);
    ug.AddEdge(2, 5, 4);
    ug.AddEdge(2, 8, 2);
    ug.AddEdge(3, 2, 7);
    ug.AddEdge(3, 4, 9);
    ug.AddEdge(3, 5, 14);
    ug.AddEdge(4, 3, 9);
    ug.AddEdge(4, 5, 10);
    ug.AddEdge(5, 2, 4);
    ug.AddEdge(5, 3, 14);
    ug.AddEdge(5, 4, 10);
    ug.AddEdge(5, 6, 2);
    ug.AddEdge(6, 5, 2);
    ug.AddEdge(6, 7, 1);
    ug.AddEdge(6, 8, 6);
    ug.AddEdge(7, 0, 8);
    ug.AddEdge(7, 1, 11);
    ug.AddEdge(7, 6, 1);
    ug.AddEdge(7, 8, 7);
    ug.AddEdge(8, 2, 2);
    ug.AddEdge(8, 6, 6);
    ug.AddEdge(8, 7, 7);

    std::cout << ug.CountTriangles() << std::endl;

    return 0;
}