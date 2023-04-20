/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/2/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    Graph(int V);
    void addEdge(int src, int dest);
    void BFS(int s);
    void printGraph();
    void printResult(const vector<bool>& visited, const vector<int>& pre, int s);

private:
    int V;
    vector<vector<int>> edge;

};
Graph::Graph(int V)
{
    this->V = V;
    edge = vector<vector<int>>(V);
}

void Graph::addEdge(int src, int dest)
{
    edge[src - 1].push_back(dest - 1);
    edge[dest - 1].push_back(src - 1);
}

void Graph::BFS(int s)
{
    vector<int> pre(V, -1);
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        vector<int> adjNodes = edge[u];
        for (int i = 0; i < adjNodes.size(); ++i) {
            int v = adjNodes[i];
            if (visited[v] == false) {
                q.push(v);
                visited[v] = true;
                pre[v] = u;
            }
        }
    }

    printResult(visited, pre, s);
}

void Graph::printGraph()
{
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i + 1 << ": ";
        vector<int> adjNodes = edge[i];
        for (int j = 0; j < adjNodes.size(); ++j) {
            cout << adjNodes[j] + 1 << " ";
        }
        cout << endl;
    }
}

void Graph::printResult(const vector<bool> &visited, const vector<int> &pre, int s)
{
    for (int v = 0; v < V; ++v) {
        if (visited[v] == false) {
            cout << "No path from " << s + 1 << " to " << v + 1 << endl;
        } else {
            cout << "path from " << s + 1 << " to " << v + 1  << " is: ";
            int f = v;
            while (pre[f] != -1) {
                cout << f + 1<< " <- ";
                f = pre[f];
            }
            cout << f + 1 << endl;
        }
    }
}


int main()
{
    int V = 8;
    int E = 7;

    Graph g(V);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(7, 8);

    g.printGraph();
    int s = 2;
    g.BFS(s - 1);

    return 0;
}

