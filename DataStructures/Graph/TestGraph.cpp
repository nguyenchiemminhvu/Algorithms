#include "Graph.h"

int main()
{
    Graph ug;
    ug.AddEdge(0, 2);
    ug.AddEdge(1, 0);
    ug.AddEdge(1, 3);
    ug.AddEdge(2, 1);
    ug.AddEdge(3, 2);

    std::vector<int> color_codes = ug.ColoringAllVertices();
    for (int i = 0; i < ug.GetNumVertices(); i++)
    {
        std::cout << i << " " << color_codes[i] << std::endl;
    }

    return 0;
}