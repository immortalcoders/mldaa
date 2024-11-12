#include <iostream>
#include <vector>
#include <climits>

struct Edge
{
    int source;
    int destination;
    int weight;
};

void bellmanFord(std::vector<Edge>& edges, int numVertices, int source) 
{
    std::vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i < numVertices; ++i)
    {
        for (const Edge& edge : edges)
        {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
            {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    for (const Edge& edge : edges)
    {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
        {
            std::cout << "Graph contains a negative weight cycle. Bellman-Ford cannot be applied." << std::endl;
            return;
        }
    }

    std::cout << "Shortest distances from source vertex " << source << " to all other vertices:" << std::endl;
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << "Vertex " << i << ": ";
        if (distance[i] == INT_MAX)
        {
            std::cout << "No path" << std::endl;
        } 
        else
        {
            std::cout << distance[i] << std::endl;
        }
    }
}

int main() 
{
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> numVertices >> numEdges;

    std::vector<Edge> edges(numEdges);

    std::cout << "Enter the source, destination, and weight for each edge:" << std::endl;
    for (int i = 0; i < numEdges; ++i) 
    {
        std::cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int sourceVertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> sourceVertex;

    bellmanFord(edges, numVertices, sourceVertex);

    return 0;
}
