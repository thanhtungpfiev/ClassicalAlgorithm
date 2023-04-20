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

using namespace std;

class Solution {
public:
    bool isCycle(vector<vector<int>>& g, int n, vector<bool>& v) {
        if (v[n]) {
            return true;
        }
        v[n] = true;
        for (auto adj : g[n]) {
            if (isCycle(g, adj, v)) {
                return true;
            }
        }
        v[n] = false;
        g[n].clear();
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto prerequisite : prerequisites){
            adjList[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (isCycle(adjList, i, visited)) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << s.canFinish(2, prerequisites) << endl;
    return 0;
}
