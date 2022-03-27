/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 26 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
    int shortestDistance(int src, int dest);

private:
    int V;
    vector<vector<iPair>> adjs;
};

Graph::Graph(int V)
{
    this->V = V;
    adjs = vector<vector<iPair>>(V);
}

void Graph::addEdge(int u, int v, int w)
{
    adjs[u].push_back({w, v});
    adjs[v].push_back({w, u});
}

void Graph::shortestPath(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vector<iPair> adj = adjs[u];
        for (int i = 0; i < adj.size(); ++i) {
            int v = adj[i].second;
            int w = adj[i].first;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Distance from Source " << src << endl;
    for (int i = 0; i < V; ++i) {
        cout << "i: " << i << " " << dist[i] << endl;
    }
}

int Graph::shortestDistance(int src, int dest)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vector<iPair> adj = adjs[u];
        for (int i = 0; i < adj.size(); ++i) {
            int v = adj[i].second;
            int w = adj[i].first;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}


int main()
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

        g.shortestPath(0);

        cout << g.shortestDistance(0, 8) << endl;
    return 0;
}
