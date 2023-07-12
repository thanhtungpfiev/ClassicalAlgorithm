/*
 * File: main.cpp
 * Project: Triangle
 * File Created: Monday, 13th June 2022 3:01:04 pm
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
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == triangle.size() - 1)
        {
            return triangle[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int right = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);
        dp[i][j] = min(left, right);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        int result = solve(0, 0, triangle, dp);
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sl.minimumTotal(triangle) << endl;
    return 0;
}