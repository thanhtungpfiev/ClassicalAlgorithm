/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 9 - 4 - 2022
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
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
    int shortestDistance(int src, int dest);
    int furtherPathInGraphFromSource(int src);
    int findMinimumFurtherPathInGraph();

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

int Graph::furtherPathInGraphFromSource(int src)
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
    sort(dist.begin(), dist.end(), greater<int>());
    return dist[0];
}

int Graph::findMinimumFurtherPathInGraph()
{
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < V; ++i) {
        pq.push(furtherPathInGraphFromSource(i));
    }
    if (!pq.empty()) {
        result = pq.top();
    }
    return result;
}


int main()
{
    int V = 5, E = 7;
    cin >> V >> E;
    Graph g(V);
    int src = 0, dest = 0, weight = 0;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest >> weight;
        g.addEdge(src - 1, dest - 1, weight);
    }
    cout << g.findMinimumFurtherPathInGraph() << endl;
    return 0;
}

