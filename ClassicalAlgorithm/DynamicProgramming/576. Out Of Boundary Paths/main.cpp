/*
 * File: main.cpp
 * Project: OutOfBoundaryPaths
 * File Created: Saturday, 16th July 2022 4:26:40 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int M = 1000000007;

    int findPaths(int m, int n, int maxMove, int i, int j)
    {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return findPaths(m, n, maxMove, i, j, memo);
    }

    int findPaths(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &memo)
    {
        if (i == m || j == n || i < 0 || j < 0)
            return 1;
        if (maxMove == 0)
            return 0;
        if (memo[i][j][maxMove] != -1)
            return memo[i][j][maxMove];
        memo[i][j][maxMove] = ((findPaths(m, n, maxMove - 1, i + 1, j, memo) + findPaths(m, n, maxMove - 1, i - 1, j, memo)) % M + (findPaths(m, n, maxMove - 1, i, j + 1, memo) + findPaths(m, n, maxMove - 1, i, j - 1, memo)) % M) % M;
        return memo[i][j][maxMove];
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
    // Output: 6
    // Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
    // Output: 12
    return 0;
}