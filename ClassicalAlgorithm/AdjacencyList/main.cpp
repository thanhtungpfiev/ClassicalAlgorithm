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

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> arr(V);
    int E;
    cin >> E;
    int v1;
    int v2;
    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2;
        addEdgeAdjacencyList(arr, v1, v2);
    }

    printAdjacencyList(arr);
    return 0;
}
