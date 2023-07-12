/*
 * File: main.cpp
 * Project: UniquePaths
 * File Created: Monday, 1st August 2022 11:10:25 am
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
    int uniquePaths(int m, int n, vector<vector<int>> &dp)
    {
        if (m < 0 || n < 0)
        {
            return 0;
        }
        if (m == 0 || n == 0)
        {
            return 1;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        dp[m][n] = uniquePaths(m - 1, n, dp) + uniquePaths(m, n - 1, dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(m - 1, n - 1, dp);
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: m = 3, n = 7
    // Output: 28

    // Input: m = 3, n = 2
    // Output: 3
    // Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    // 1. Right -> Down -> Down
    // 2. Down -> Down -> Right
    // 3. Down -> Right -> Down

    return 0;
}