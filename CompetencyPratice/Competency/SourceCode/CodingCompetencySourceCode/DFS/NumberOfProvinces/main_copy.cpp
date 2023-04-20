/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 9/29/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int source) {
        visited[source] = true;
        vector<int> temp = adj[source];
        for (int i = 0; i < temp.size(); ++i) {
            if (visited[temp[i]] == false) {
                dfs(adj, visited, temp[i]);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        vector<vector<int>> adj(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 1) {
                   adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < adj.size(); ++i) {
            if (visited[i] == false) {
                cnt++;
                dfs(adj, visited, i);
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0 , 1}};
    int cnt = s.findCircleNum(isConnected);
    cout << cnt << endl;
    return 0;
}
