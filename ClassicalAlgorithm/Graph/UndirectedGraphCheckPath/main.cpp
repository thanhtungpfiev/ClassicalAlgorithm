/*
 * File: main.cpp
 * Project: Find if there is a path between two vertices in an undirected graph
 * File Created: Tuesday, 2nd August 2022 10:53:47 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
// C++ program to check if there is exist a path between
// two vertices of an undirected graph.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// function to add an edge to graph
void addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// A BFS based function to check whether d is reachable from s.
bool isReachable(int s, int d)
{
    // Base case
    if (s == d)
        return true;

    int n = (int)adj.size();

    // Mark all the vertices as not visited
    vector<bool> visited(n, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        s = q.front();
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited  and enqueue it
        for (auto x : adj[s])
        {

            // If this adjacent node is the destination node,
            // then return true
            if (x == d)
                return true;

            // Else, continue to do BFS
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    // If BFS is complete without visiting d
    return false;
}

// Driver program to test methods of graph class
int main()
{
    int n = 4;
    // Create a graph in the above diagram
    adj = vector<vector<int>>(n);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    int u = 1, v = 3;
    if (isReachable(u, v))
        cout << "\n There is a path from " << u << " to " << v;
    else
        cout << "\n There is no path from " << u << " to " << v;

    return 0;
}