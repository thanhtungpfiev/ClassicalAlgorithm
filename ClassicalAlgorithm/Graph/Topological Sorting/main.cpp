/*
 * File: main.cpp
 * Project: TopologicalSorting
 * File Created: Wednesday, 17th August 2022 9:33:12 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// class top
class Graph
{
    int V; // No. of vertices
    vector<vector<int>> adjs;
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSort();
};

void Graph::topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    for (auto i : adjs[v])
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, st);
        }
    }
    // Push current vertex to stack
    // which stores result
    st.push(v);
}

Graph::Graph(int v)
{
    this->V = v;
    adjs = vector<vector<int>>(V);
}

void Graph::addEdge(int v, int w)
{
    adjs[v].push_back(w);
}

void Graph::topologicalSort()
{
    stack<int> st;

    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, st);
        }
    }

    // Print contents of stack
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main(int argc, char **argv)
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    g.topologicalSort();
    return 0;
}