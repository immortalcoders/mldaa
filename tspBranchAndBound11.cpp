#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>

const int N = 15;

int n;
int graph[N][N];
std::vector<int> minPath; 
int minCost = std::numeric_limits<int>::max(); 

void copyToMinPath(const std::vector<int>& path)
{
    minPath.clear();
    for (int i = 0; i < path.size(); i++)
    {
        minPath.push_back(path[i]);
    }
}

int calculatePathCost(const std::vector<int>& path)
{
    int cost = 0;
    for (int i = 0; i < path.size() - 1; i++)
    {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path.back()][path[0]];
    return cost;
}

void tspBranchAndBound(int currCity, std::vector<int> path, std::vector<bool> visited, int bound)
{
    path.push_back(currCity);
    visited[currCity] = true;

    if (path.size() == n)
    {
        if (graph[currCity][path[0]] != 0)
        {
            int currentPathCost = calculatePathCost(path);
            if (currentPathCost < minCost)
            {
                minCost = currentPathCost;
                copyToMinPath(path);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[currCity][i] != 0)
        {
            int currentPathCost = calculatePathCost(path);
            int newPathBound = bound - (currentPathCost / 2);
            if (newPathBound + currentPathCost < minCost)
            {
                tspBranchAndBound(i, path, visited, newPathBound);
            }

            path.pop_back();
            visited[i] = false;
        }
    }
}

void printPathAndCost()
{
    std::cout << "Optimal TSP Path: ";
    for (int city : minPath)
    {
        std::cout << city << " -> ";
    }
    std::cout << minPath[0] << std::endl; 
    std::cout << "Optimal TSP Cost: " << minCost << std::endl;
}

int main() 
{
    std::cout << "Enter the number of cities: ";
    std::cin >> n;

    std::cout << "Enter the adjacency matrix (0 for the same city, a positive integer for distance):" << std::endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            std::cin >> graph[i][j];
        }
    }

    std::vector<int> path;
    std::vector<bool> visited(n, false);
    path.push_back(0);

    int bound = 0; 
    for (int i = 0; i < n; i++) 
    {
        bound += graph[i][0]; 
    }

    tspBranchAndBound(0, path, visited, bound);
    printPathAndCost();

    return 0;
}
