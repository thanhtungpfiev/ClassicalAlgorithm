/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/1/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    void shortestPath(int s);

    int V;
    vector<vector<iPair>> edges;
};

Graph::Graph(int V)
{
    this->V = V;
    edges = vector<vector<iPair>>(V);
}

void Graph::addEdge(int src, int dest, int weight)
{
    edges[src].push_back(make_pair(weight, dest));
    edges[dest].push_back(make_pair(weight, src));
}

void Graph::shortestPath(int s)
{
    vector<int> d(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    pq.push(make_pair(0, s));
    d[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vector<iPair> adjNodes = edges[u];
        for (int i = 0; i < adjNodes.size(); ++i) {
            int v = adjNodes[i].second;
            int weight = adjNodes[i].first;
            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                pq.push(make_pair(d[v], v));
            }
        }
    }

    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<< d[i]<< endl;
    cout << endl;
}

int main()
{
    int V = 9;
    int E = 14;
    Graph g(V);
    std::ifstream fileInput("D:/QT/CompetencyCoding/Competency/SourceCode/30thProblem/input.txt");
    int scr, dest, weight;
    while (fileInput >> scr >> dest >> weight) {
        g.addEdge(scr, dest, weight);
    }

    g.shortestPath(0);

    return 0;
}
