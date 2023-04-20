/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/30/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

int minDistance(const vector<int>& d, const vector<bool>& unvisited)
{
    int minDis = INT_MAX, minIndex;
    for (int v = 0; v < d.size(); ++v) {
        if (unvisited[v] == true && d[v] <= minDis) {
            minDis = d[v];
            minIndex = v;
        }
    }
    return minIndex;
}

vector<int> dijkstra(int V, vector<vector<int>>& adj, int S)
{
    vector<int> pre(V, S); // Trace from S -> all vertexes
    vector<int> d(V, INT_MAX); // Distance from v -> S
    vector<bool> unvisited(V, true);

    d[S] = 0;
    pre[S] = -1;

    for (int i = 0; i < V - 1; ++i) {
        int u = minDistance(d, unvisited);
        if (d[u] == INT_MAX) break;
        unvisited[u] = false;

        for (int v = 0; v < V; ++v) {
            if (unvisited[v] == true && adj[u][v] && d[u] != INT_MAX && ((d[u] + adj[u][v]) < d[v])) {
                d[v] = d[u] + adj[u][v];
                pre[v] = u;
            }
        }
    }
    return d;
}

int main()
{

    int V = 9;
    int E = 14;
    vector<vector<int>> graph(V, vector<int>(V));
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/28thProblem/input.txt");
    int scr, dest, weight;
    while (fileInput >> scr >> dest >> weight) {
        graph[scr][dest] = weight;
        graph[dest][scr] = weight;
    }

    vector<int> d = dijkstra(V, graph, 0);
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<< d[i]<< endl;
    cout << endl;

    return 0;
}
