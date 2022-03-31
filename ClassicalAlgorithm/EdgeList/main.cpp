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

struct Edge
{
    int u;
    int v;
};

void addEdgeList(vector<Edge>& arr, int u, int v)
{
    Edge e;
    e.u = u;
    e.v = v;
    arr.push_back(e);
}

void printEdgeList(const vector<Edge>& arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i].u << " " << arr[i].v << endl;
    }
}

int main()
{
    int V;
    cin >> V;
    int E;
    cin >> E;
    vector<Edge> arr;
    int v1;
    int v2;
    for (int i = 0; i < E; ++i) {
        cin >> v1 >> v2;
        addEdgeList(arr, v1, v2);
    }
    printEdgeList(arr);
    return 0;
}
