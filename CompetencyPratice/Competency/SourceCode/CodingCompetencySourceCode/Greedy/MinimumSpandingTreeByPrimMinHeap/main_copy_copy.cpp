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
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

void addEdgeAdjacencyList(vector<vector<iPair>>& graph, int src, int dest, int weight)
{
    graph[src].push_back(make_pair(weight, dest));
    graph[dest].push_back(make_pair(weight, src));
}

void printAdjacencyList(const vector<vector<iPair>>& graph)
{
    for (int scr = 0; scr < graph.size(); ++scr) {
        cout << scr << ": ";
        vector<iPair> temp = graph[scr];
        for (int dest = 0; dest < temp.size(); ++dest) {
            iPair adjNode = temp[dest];
            cout << adjNode.second << "(" << adjNode.first << ") ";
        }
        cout << endl;
    }
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

void primMST(const vector<vector<iPair>>& graph)
{
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> isInMST(V, false);
    key[0] = 0;

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (isInMST[u]) {
            continue;
        }
        isInMST[u] = true;
        vector<iPair> adjNodes = graph[u];
        for (int i = 0; i < adjNodes.size(); ++i) {
            iPair adjNode = adjNodes[i];
            int v = adjNode.second;
            int w = adjNode.first;
            if (isInMST[v] == false && key[v] > w) {
                key[v] = w;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
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
    vector<vector<iPair>> graph(V);
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/27thProblem/input.txt");
    int src, dest, weight;
    while (fileInput >> src >> dest >> weight) {
        addEdgeAdjacencyList(graph, src, dest, weight);
    }

    primMST(graph);
    return 0;
}
