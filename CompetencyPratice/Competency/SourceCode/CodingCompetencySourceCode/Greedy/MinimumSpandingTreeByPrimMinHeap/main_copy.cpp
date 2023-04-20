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
#include <fstream>
#include <algorithm>

using namespace std;

struct AdjNode
{
    int dest;
    int weight;
    AdjNode(int dest1, int weight1) {
        dest = dest1;
        weight = weight1;
    }
};

void addEdgeAdjacencyList(vector<vector<AdjNode>>& graph, int scr, int dest, int weight)
{
    graph[src].push_back(AdjNode(dest, weight));
    graph[dest].push_back(AdjNode(scr, weight));
}

void printAdjacencyList(const vector<vector<AdjNode>>& graph)
{
    for (int scr = 0; scr < graph.size(); ++scr) {
        cout << scr << ": ";
        vector<AdjNode> temp = graph[scr];
        for (int dest = 0; dest < temp.size(); ++dest) {
            AdjNode adjNode = temp[dest];
            cout << adjNode.dest << "(" << adjNode.weight << ") ";
        }
        cout << endl;
    }
}

struct MinHeapNode
{
    int v;
    int key;
    MinHeapNode(int v1, int key1) {
        v = v1;
        key = key1;
    }
};

bool myComp(const MinHeapNode& a, const MinHeapNode& b)
{
    return a.key < b.key;
}


int printArr(const vector<int>& arr, const vector<int> &key)
{
    int minimumCost = 0;
    for (int i = 1; i < arr.size(); ++i) {
        cout << arr[i] << "-" << i << ": " << key[i] << endl;
        minimumCost += key[i];
    }
    return minimumCost;
}

void primMST(const vector<vector<AdjNode>>& graph)
{
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    key[0] = 0;

    vector<MinHeapNode> minHeap;
    for (int v = 0; v < V; ++v) {
        minHeap.push_back(MinHeapNode(v, key[v]));
    }
    std::sort(minHeap.begin(), minHeap.end(), myComp);

    while (!minHeap.empty()) {
        MinHeapNode minHeapNode = minHeap.front();
        minHeap.erase(minHeap.begin());
        int u = minHeapNode.v;
        vector<AdjNode> adjNodes = graph[u];
        for (int i = 0; i < adjNodes.size(); ++i) {
            AdjNode adjNode = adjNodes[i];
            vector<MinHeapNode>::iterator it = find_if(minHeap.begin(), minHeap.end(),
                                                       [&](MinHeapNode const & temp) {return temp.v == adjNode.dest;});
            if (it != minHeap.end() && it->key > adjNode.weight) {
                key[adjNode.dest] = adjNode.weight;
                parent[adjNode.dest] = u;
                it->key = adjNode.weight;
                std::sort(minHeap.begin(), minHeap.end(), myComp);
            }
        }
    }

    // print edges of MST
    cout << printArr(parent, key) << endl;
}

int main()
{
    int V = 9;
    int E = 14;
    vector<vector<AdjNode>> graph(V);
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/27thProblem/input.txt");
    int src, dest, weight;
    while (fileInput >> src >> dest >> weight) {
        addEdgeAdjacencyList(graph, src, dest, weight);
    }

    primMST(graph);
    return 0;
}
