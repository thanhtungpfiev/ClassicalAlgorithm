/*
 * File: main.cpp
 * Project: PrimMinimumSpanningTree
 * File Created: Sunday, 21st August 2022 11:23:24 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    vector<vector<iPair>> adjs;

public:
    Graph(int V);

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // Print MST using Prim's algorithm
    void primMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adjs = vector<vector<iPair>>(V);
}

void Graph::addEdge(int u, int v, int w)
{
    adjs[u].push_back(make_pair(v, w));
    adjs[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0; // Taking vertex 0 as Source

    // Create a vector for keys and initialize all keys as infinite (INF)
    vector<int> key(V, INT_MAX);

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize its key as 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // Different key values for same vertex may exist in the priority queue.
        //  The one with the least key value is always processed first.
        //  Therefore, ignore the rest.
        if (inMST[u] == true)
        {
            continue;
        }
        inMST[u] = true; // Include vertex in MST

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto &i : adjs[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i.first;
            int w = i.second;

            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > w)
            {
                // Updating key of v
                key[v] = w;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main(int argc, char **argv)
{
    // create the graph given in above figure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();

    return 0;
}