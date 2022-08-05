/*
 * File: main.cpp
 * Project: ClimbingStairs
 * File Created: Monday, 1st August 2022 10:50:17 am
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
    int climbStairs(int n, vector<int> &dp)
    {
        if (n <= 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return climbStairs(n, dp);
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: n = 2
    // Output: 2
    // Explanation: There are two ways to climb to the top.
    // 1. 1 step + 1 step
    // 2. 2 steps

    // Input: n = 3
    // Output: 3
    // Explanation: There are three ways to climb to the top.
    // 1. 1 step + 1 step + 1 step
    // 2. 1 step + 2 steps
    // 3. 2 steps + 1 step
    return 0;
}