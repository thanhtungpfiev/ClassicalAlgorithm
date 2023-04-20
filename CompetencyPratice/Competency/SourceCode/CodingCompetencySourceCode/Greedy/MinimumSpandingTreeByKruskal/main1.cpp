/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/29/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// a structure to represent an edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges
    vector<Edge> edge;
};

struct subset
{
    int parent;
    int rank;
};

// Creates a graph with V vertices and E edges
Graph createGraph(int V, int E)
{
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edge = vector<Edge>(E);
    return graph;
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(vector<subset>& subsets, int i)
{
    // find root and make root as parent of i (path
    // compression
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(vector<subset>& subsets, int xroot, int yroot)
{
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// The main function to check whether a given graph contains
// cycle or not
bool isCycle(const Graph& graph)
{
    int V = graph.V;
    int E = graph.E;

    vector<subset> subsets = vector<subset>(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through all edges of graph, find sets of both
    // vertices of every edge, if sets are same, then there
    // is cycle in graph.
    for (int e = 0; e < E; ++e) {
        int x = find(subsets, graph.edge[e].src);
        int y = find(subsets, graph.edge[e].dest);

        if (x == y) {
            return true;
        }
        Union(subsets, x, y);
    }
    return false;
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const Edge& a, const Edge& b)
{
    return a.weight < b.weight;
}

void printEdge(const vector<Edge>& edge)
{
    for (int e = 0; e < edge.size(); ++e) {
        cout << "src: " << edge[e].src << " "
             << "dest: " << edge[e].dest << " "
             << "weight: " << edge[e].weight << endl;
    }
}

// The main function to construct MST using Kruskal's
// algorithm
void Kruskal(Graph& graph)
{
    int V = graph.V;
    int E = graph.E;
    vector<Edge> result;
    int i = 0;

    // Step 1: Sort all the edges in non-decreasing
    // order of their weight.
    std::sort(graph.edge.begin(), graph.edge.end(), myComp);

    vector<subset> subsets = vector<subset>(V);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (result.size() < (V - 1) && i < E) {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        Edge next_edge = graph.edge[i];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
        }
        ++i;
    }

    int minimumCost = 0;
    for (int i = 0; i < result.size(); ++i) {
        cout << "src: " << result[i].src << " "
             << "dest: " << result[i].dest << " "
             << "weight: " << result[i].weight << endl;
        minimumCost += result[i].weight;
    }
    cout << minimumCost << endl;
}

int main()
{
    int V = 9;
    int E = 14;
    Graph graph = createGraph(V, E);
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/build-25thProblem-Desktop_Qt_5_11_1_MinGW_32bit-Debug/debug/input.txt");
    std::string str;
    int scr, dest, weight;
    int i = 0;
    while (fileInput >> scr >> dest >> weight) {
        graph.edge[i].src = scr;
        graph.edge[i].dest = dest;
        graph.edge[i].weight = weight;
        ++i;
    }

    Kruskal(graph);
    return 0;
}
