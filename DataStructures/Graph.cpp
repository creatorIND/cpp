#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

class Graph
{
private:
    std::unordered_map<int, std::unordered_set<int>> adjacencyList;

public:
    void addVertex(int vertex)
    {
        // If the vertex is already present, return
        if (adjacencyList.find(vertex) != adjacencyList.end())
        {
            std::cout << "Vertex " << vertex << " already exists." << std::endl;
            return;
        }

        // Add an empty list for the new vertex
        adjacencyList[vertex] = std::unordered_set<int>();
        std::cout << "Vertex " << vertex << " added." << std::endl;
    }

    void removeVertex(int vertex)
    {
        // If the vertex doesn't exist, return
        if (adjacencyList.find(vertex) == adjacencyList.end())
        {
            std::cout << "Vertex " << vertex << " doesn't exist." << std::endl;
            return;
        }

        // Remove the vertex and its associated edges
        adjacencyList.erase(vertex);
        for (auto &entry : adjacencyList)
        {
            entry.second.erase(vertex);
        }

        std::cout << "Vertex " << vertex << " removed." << std::endl;
    }

    void addEdge(int source, int destination)
    {
        // If either the source or destination vertex doesn't exist, return
        if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end())
        {
            std::cout << "One or both vertices doesn't exist" << std::endl;
            return;
        }

        // Add the edge to the adjacency lists of both vertices
        adjacencyList[source].insert(destination);
        adjacencyList[destination].insert(source);
        std::cout << "Edge (" << source << " <-> " << destination << ") added." << std::endl;
    }

    void removeEdge(int source, int destination)
    {
        // If either the source or destination vertex doesn't exist, return
        if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end())
        {
            std::cout << "One or both vertices doesn't exist." << std::endl;
            return;
        }

        // Remove the edge from the adjacency lists of both vertices
        adjacencyList[source].erase(destination);
        adjacencyList[destination].erase(source);
        std::cout << "Edge (" << source << " <-> " << destination << ") removed." << std::endl;
    }

    void printGraph()
    {
        for (const auto &entry : adjacencyList)
        {
            std::cout << "Vertex " << entry.first << ": ";
            for (const auto &neighbor : entry.second)
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void DFSTraversal(int startVertex)
    {
        // Check if the start vertex exists in the graph
        if (adjacencyList.find(startVertex) == adjacencyList.end())
        {
            std::cout << "Start vertex " << startVertex << " not found in the graph." << std::endl;
            return;
        }

        std::unordered_set<int> visited;
        std::stack<int> st;

        st.push(startVertex);

        while (!st.empty())
        {
            int currentVertex = st.top();
            st.pop();

            if (visited.find(currentVertex) == visited.end())
            {
                std::cout << currentVertex << " ";
                visited.insert(currentVertex);

                for (const auto &neighbor : adjacencyList[currentVertex])
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        st.push(neighbor);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void BFSTraversal(int startVertex)
    {
        // Check if the start vertex exists in the graph
        if (adjacencyList.find(startVertex) == adjacencyList.end())
        {
            std::cout << "Start vertex " << startVertex << " not found in the graph." << std::endl;
            return;
        }

        std::unordered_set<int> visited;
        std::queue<int> qu;

        qu.push(startVertex);

        while (!qu.empty())
        {
            int currentVertex = qu.front();
            qu.pop();

            if (visited.find(currentVertex) == visited.end())
            {
                std::cout << currentVertex << " ";
                visited.insert(currentVertex);

                for (const auto &neighbor : adjacencyList[currentVertex])
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        qu.push(neighbor);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void DFSTraversalRecursive(int startVertex)
    {
        // Check if the start vertex exists in the graph
        if (adjacencyList.find(startVertex) == adjacencyList.end())
        {
            std::cout << "Start vertex " << startVertex << " not found in the graph." << std::endl;
            return;
        }

        std::unordered_set<int> visited;
        DFSRecursiveHelper(startVertex, visited);
        std::cout << std::endl;
    }

private:
    void DFSRecursiveHelper(int currentVertex, std::unordered_set<int> &visited)
    {
        if (visited.find(currentVertex) != visited.end())
            return;

        std::cout << currentVertex << " ";
        visited.insert(currentVertex);

        for (const auto &neighbor : adjacencyList[currentVertex])
        {
            DFSRecursiveHelper(neighbor, visited);
        }
    }
};

int main()
{
    Graph graph;

    // Add vertices
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);
    graph.addVertex(6);
    graph.addVertex(7);

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 7);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(6, 7);

    graph.printGraph();

    graph.DFSTraversal(1);

    // Remove edges
    // graph.removeEdge(2, 3);
    // graph.removeEdge(4, 1);

    // Remove vertices
    // graph.removeVertex(3);
    // graph.removeVertex(5);

    // graph.printGraph();

    return 0;
}