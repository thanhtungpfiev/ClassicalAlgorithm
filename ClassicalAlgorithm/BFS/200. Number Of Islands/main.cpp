/*
 * File: main.cpp
 * Project: NumberOfIslands
 * File Created: Friday, 29th July 2022 11:31:38 am
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
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};
        queue<mPair> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        mPair curr = q.front();
                        q.pop();
                        int currX = curr.first;
                        int currY = curr.second;
                        if (grid[currX][currY] == '1')
                        {
                            grid[currX][currY] = '0';
                        }
                        for (int k = 0; k < 4; ++k)
                        {
                            int newX = currX + r[k];
                            int newY = currY + c[k];
                            if (newX < 0 || newX >= m)
                                continue;
                            if (newY < 0 || newY >= n)
                                continue;
                            if (grid[newX][newY] == '1')
                            {
                                grid[newX][newY] = '0';
                                q.push(make_pair(newX, newY));
                            }
                        }
                    }
                    ++count;
                }
            }
        }
        return count;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: grid = [
    // ["1","1","1","1","0"],
    // ["1","1","0","1","0"],
    // ["1","1","0","0","0"],
    // ["0","0","0","0","0"]
    // ]
    // Output: 1

    // Input: grid = [
    // ["1","1","0","0","0"],
    // ["1","1","0","0","0"],
    // ["0","0","1","0","0"],
    // ["0","0","0","1","1"]
    // ]
    // Output: 3
    return 0;
}