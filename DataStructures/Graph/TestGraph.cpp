#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 2);
    ug.AddEdge(2, 3);
    ug.AddEdge(3, 0);
    
    std::cout << (ug.HasCycle() ? "Has Cycle" : "No Cycle") << std::endl;

    return 0;
}