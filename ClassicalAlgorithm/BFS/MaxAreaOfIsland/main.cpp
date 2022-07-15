/*
 * File: main.cpp
 * Project: MaxAreaOfIsland
 * File Created: Friday, 15th July 2022 10:51:03 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> st;
        vector<int> r{-1, 0, 1, 0};
        vector<int> c{0, 1, 0, -1};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int count = 0;
                    st.push(make_pair(i, j));
                    while (!st.empty())
                    {
                        pair<int, int> temp = st.top();
                        st.pop();
                        int i1 = temp.first;
                        int j1 = temp.second;
                        grid[i1][j1] = 0;
                        ++count;
                        for (int k = 0; k < 4; ++k)
                        {
                            if (i1 + r[k] < 0 || i1 + r[k] > m - 1)
                                continue;
                            if (j1 + c[k] < 0 || j1 + c[k] > n - 1)
                                continue;
                            if (grid[i1 + r[k]][j1 + c[k]] == 1)
                            {
                                grid[i1 + r[k]][j1 + c[k]] = 0;
                                st.push(make_pair(i1 + r[k], j1 + c[k]));
                            }
                        }
                    }
                    result = max(count, result);
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    // Output: 6
    // Explanation: The answer is not 11, because the island must be connected 4-directionally.
    // Input: grid = [[0,0,0,0,0,0,0,0]]
    // Output: 0
    return 0;
}