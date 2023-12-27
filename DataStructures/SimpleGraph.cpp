#include <iostream>
#include <vector>

class SimpleGraph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;

public:
    SimpleGraph(int n) : numVertices(n)
    {
        adjList.resize(numVertices);
    }

    void addEdge(int u, int v)
    {
        adjList.at(u).push_back(v);
        adjList.at(v).push_back(u);
    }

    void printGraph()
    {
        for (int i{0}; i < numVertices; i++)
        {
            std::cout << "Vertex " << i << ": ";
            for (int j : adjList[i])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    SimpleGraph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}