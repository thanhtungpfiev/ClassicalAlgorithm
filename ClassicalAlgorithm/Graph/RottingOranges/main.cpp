/*
 * File: main.cpp
 * Project: RottingOranges
 * File Created: Friday, 26th August 2022 10:14:28 am
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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int result = -1; // initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        int m = grid.size();
        int n = grid[0].size();
        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};
        queue<mPair> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh;
                }
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            { // BFS for each rotten orange start at each minute
                mPair temp = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int newX = temp.first + r[i];
                    int newY = temp.second + c[i];
                    if (newX < 0 || newX >= m)
                        continue;
                    if (newY < 0 || newY >= n)
                        continue;
                    if (grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        q.push(make_pair(newX, newY));
                        fresh--;
                    }
                }
            }
            result++; // incremented after each minute passes
        }
        if (fresh > 0)
            return -1; // if fresh>0 that means there are fresh oranges left
        if (result == -1)
            return 0; // we initialised with -1, so if there were no oranges it'd take 0 mins.
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}