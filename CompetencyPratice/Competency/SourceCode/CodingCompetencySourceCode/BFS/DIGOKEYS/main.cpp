/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/1/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph
{
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void sortGraph();
    void bfs();
private:
    int V;
    vector<vector<int>> edges;
};

Graph::Graph(int V)
{
    this->V = V;
    edges = vector<vector<int>>(V);
}

void Graph::addEdge(int src, int dest)
{
    edges[src - 1].push_back(dest - 1);
}

void Graph::bfs()
{
    vector<int> trace(V, -1);
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vector<int> edge = edges[u];
        for (int i = 0; i < edge.size(); ++i) {
            int v = edge[i];
            if (visited[v] == false) {
                visited[v] = true;
                trace[v] = u;
                q.push(v);
            }
        }
    }
    if (visited[V - 1] == false) {
        cout << -1 << endl;
    } else {
        int f = V - 1;
        vector<int> result;
        while (trace[f] != -1) {
            result.insert(result.begin(), f + 1);
            f = trace[f];
        }
        result.insert(result.begin(), f + 1);
        cout << result.size() - 1 << endl;
        for (int i = 0; i < result.size() - 1; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

}

void Graph::sortGraph()
{
    for (int i = 0; i < V; ++i) {
        vector<int> edge = edges[i];
        sort(edge.begin(), edge.end());
        edges[i] = edge;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        Graph g(N);
        for (int n = 1; n < N; ++n) {
            int M;
            cin >> M;
            for (int m = 1; m <= M; ++m) {
                int dest;
                cin >> dest;
                g.addEdge(n, dest);
            }
        }
        g.sortGraph();
        g.bfs();
    }
    return 0;
}
