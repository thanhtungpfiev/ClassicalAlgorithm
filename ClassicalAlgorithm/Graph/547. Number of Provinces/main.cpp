/*
 * File: main.cpp
 * Project: 547. Number of Provinces
 * File Created: Friday, 22nd September 2023 1:33:51 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        int N  = isConnected.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j && isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(N, false);
        stack<int> st;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                result++;
                st.push(i);
                visited[i] = true;
                while (!st.empty()) {
                    int u = st.top();
                    st.pop();
                    for (int k = 0; k < adj[u].size(); ++k) {
                        if (visited[adj[u][k]] == false) {
                            visited[adj[u][k]] = true;
                            st.push(adj[u][k]);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}