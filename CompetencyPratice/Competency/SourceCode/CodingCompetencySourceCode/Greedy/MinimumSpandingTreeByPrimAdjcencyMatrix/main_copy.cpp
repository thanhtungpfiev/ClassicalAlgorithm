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
#include <climits>
#include <fstream>

using namespace std;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST

int minKey(const vector<int>& key, const vector<bool>& mstSet)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < key.size(); ++v) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]

int printMST(const vector<int>& parent, const vector<vector<int>>& graph)
{
    int minimumWeight = 0;
    for (int i = 1; i < parent.size(); ++i) {
//        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
        minimumWeight += graph[parent[i]][i];
    }
    return minimumWeight;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation

void primMST(const vector<vector<int>>& graph)
{
    // Array to store constructed MST
    vector<int> parent(graph.size());

    // Key values used to pick minimum weight edge in cut
    vector<int> key(graph.size(), INT_MAX);

    // To represent set of vertices included in MST
    vector<bool> mstSet(graph.size(), false);

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < graph.size() - 1; ++count) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < graph.size(); ++v) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << printMST(parent, graph) << endl;
}

int main()
{
    int V = 9;
    int E = 14;
    vector<vector<int>> graph(V, vector<int>(V));
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/26thProblem/input.txt");
    int scr, dest, weight;
    while (fileInput >> scr >> dest >> weight) {
        graph[scr][dest] = weight;
        graph[dest][scr] = weight;
    }

    primMST(graph);

    return 0;
}
