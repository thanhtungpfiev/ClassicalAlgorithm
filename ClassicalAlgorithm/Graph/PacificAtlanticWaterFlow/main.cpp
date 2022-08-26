/*
 * File: main.cpp
 * Project: PacificAtlanticWaterFlow
 * File Created: Friday, 26th August 2022 2:37:46 pm
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
    typedef pair<int, int> mPair;
    vector<int> r{-1, 0, 1, 0};
    vector<int> c{0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pVisited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> aVisited = vector<vector<bool>>(m, vector<bool>(n, false));
        queue<mPair> pQueue;
        queue<mPair> aQueue;

        // First add all cells next to left & top edge (adjacent to pacific) and add all cells next to right and bottom edge (adjacent to atlantic)
        for (int i = 0; i < m; ++i)
        {
            pVisited[i][0] = true;
            pQueue.push(make_pair(i, 0));
            aVisited[i][n - 1] = true;
            aQueue.push(make_pair(i, n - 1));
        }

        for (int j = 0; j < n; ++j)
        {
            pVisited[0][j] = true;
            pQueue.push(make_pair(0, j));
            aVisited[m - 1][j] = true;
            aQueue.push(make_pair(m - 1, j));
        }

        // BFS to find all cell can flow the each ocean
        bfs(pVisited, pQueue, heights, m, n);
        bfs(aVisited, aQueue, heights, m, n);

        // The result is intersect of 2 maps of each ocean
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pVisited[i][j] && aVisited[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void bfs(vector<vector<bool>> &visited, queue<mPair> &q, vector<vector<int>> &heights, int m, int n)
    {
        while (!q.empty())
        {
            mPair tmp = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int newX = tmp.first + r[i];
                int newY = tmp.second + c[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] || heights[newX][newY] < heights[tmp.first][tmp.second])
                {
                    continue;
                }
                visited[newX][newY] = true;
                q.push(make_pair(newX, newY));
            }
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}