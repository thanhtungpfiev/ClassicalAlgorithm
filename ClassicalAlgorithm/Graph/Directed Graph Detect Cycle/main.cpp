/*
 * File: main.cpp
 * Project: DirectedGraphDetectCycle
 * File Created: Thursday, 4th August 2022 11:07:12 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;                                                             // No. of vertices
    vector<vector<int>> adjs;                                          // vector contain adjacencies;
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &rs); // used by isCyclic()

public:
    Graph(int V);               // Constructor
    void addEdge(int v, int w); // to add an edge to the graph
    bool isCyclic();            // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adjs = vector<vector<int>>(V);
}

void Graph::addEdge(int v, int w)
{
    adjs[v].push_back(w); // Add w to v's list
}

bool Graph::isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
{
    if (visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        // Recur for all the vertices adjacent to this vertex;
        for (auto &e : adjs[v])
        {
            if (!visited[e] && isCyclicUtil(e, visited, recStack))
            {
                return true;
            }
            else if (recStack[e])
            {
                return true;
            }
        }
    }
    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion stack
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}