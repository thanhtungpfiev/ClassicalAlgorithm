/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/27/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void addEdgeAdjacencyMatrix(vector<vector<int>>& arr, int u, int v)
{
    arr[u][v] = 1;
    arr[v][u] = 1;
}

void printAdjacencyMatrix(const vector<vector<int>>& arr)
{
    for (int u = 0; u < arr.size(); ++u) {
        for (int v = 0; v < arr.size(); ++v) {
            cout << arr[u][v] << " ";
        }
        cout << endl;
    }
}

void addEdgeAdjacencyList(vector<vector<int>>& arr, int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void printAdjacencyList(const vector<vector<int>>& arr)
{
    for (int u = 0; u < arr.size(); ++u) {
        cout << u << ": ";
        vector<int> temp = arr[u];
        for (int v = 0; v < temp.size(); ++v) {
            cout << temp[v] << " ";
        }
        cout << endl;
    }
}

struct Edge
{
    int u;
    int v;
};

void addEdgeList(vector<Edge>& arr, int u, int v)
{
    Edge e;
    e.u = u;
    e.v = v;
    arr.push_back(e);
}

void printEdgeList(const vector<Edge>& arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i].u << " " << arr[i].v << endl;
    }
}

int main()
{
    // Display graph by adjacency matrix
//    int V;
//    cin >> V;
//    vector<vector<int>> arr(V, vector<int>(V));
//    int E;
//    cin >> E;
//    int v1;
//    int v2;
//    for (int i = 0; i < E; ++i) {
//        cin >> v1 >> v2;
//        addEdgeAdjacencyMatrix(arr, v1, v2);
//    }

//    printAdjacencyMatrix(arr);

    // Display graph by adjacency list
//    int V;
//    cin >> V;
//    vector<vector<int>> arr(V);
//    int E;
//    cin >> E;
//    int v1;
//    int v2;
//    for (int i = 0; i < E; ++i) {
//        cin >> v1 >> v2;
//        addEdgeAdjacencyList(arr, v1, v2);
//    }

//    printAdjacencyList(arr);

    // Display grap by edge list
//    int V;
//    cin >> V;
//    int E;
//    cin >> E;
//    vector<Edge> arr;
//    int v1;
//    int v2;
//    for (int i = 0; i < E; ++i) {
//        cin >> v1 >> v2;
//        addEdgeList(arr, v1, v2);
//    }
//    printEdgeList(arr);
    return 0;
}
