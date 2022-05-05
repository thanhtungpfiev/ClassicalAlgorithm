/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/31/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
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

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> arr(V, vector<int>(V));
    int E;
    cin >> E;
    int v1;
    int v2;
    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2;
        addEdgeAdjacencyMatrix(arr, v1, v2);
    }
    return 0;
}
