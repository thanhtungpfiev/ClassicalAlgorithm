/*
 * File: main.cpp
 * Project: UndirectedGraphDetectCycle
 * File Created: Thursday, 4th August 2022 2:12:33 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Class for an undirected graph
class Graph
{
    int V;                    // No. of vertices in graph
    vector<vector<int>> adjs; // Array of edges in graph
    bool isCyclicUtil(int v, vector<bool> &visited, int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adjs = vector<vector<int>>(V);
}

void Graph::addEdge(int v, int w)
{

    // Add w to v’s list.
    adjs[v].push_back(w);

    // Add v to w’s list.
    adjs[w].push_back(v);
}

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v
bool Graph::isCyclicUtil(int v, vector<bool> &visited, int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    for (auto &e : adjs[v])
    {
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[e])
        {
            if (isCyclicUtil(e, visited, v))
            {
                return true;
            }
        }
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (e != parent)
        {
            return true;
        }
    }
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{

    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    vector<bool> visited(V, false);

    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    {
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}

// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";

    return 0;
}