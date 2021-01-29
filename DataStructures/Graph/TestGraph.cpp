#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 1);
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 0);
    ug.AddEdge(1, 2);
    ug.AddEdge(1, 4);
    ug.AddEdge(2, 0);
    ug.AddEdge(2, 1);
    ug.AddEdge(2, 4);
    ug.AddEdge(3, 4);
    ug.AddEdge(4, 1);
    ug.AddEdge(4, 2);
    ug.AddEdge(4, 3);

    std::vector<int> color_codes = ug.ColoringAllVertices();
    for (int i = 0; i < ug.GetNumVertices(); i++)
    {
        std::cout << i << " " << color_codes[i] << std::endl;
    }

    return 0;
}