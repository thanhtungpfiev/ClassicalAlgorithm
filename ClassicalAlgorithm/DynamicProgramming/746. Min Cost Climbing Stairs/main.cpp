/*
 * File: main.cpp
 * Project: 746. Min Cost Climbing Stairs
 * File Created: Monday, 21st August 2023 12:10:48 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return dp[n];
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}