/*
 * File: main.cpp
 * Project: KInversePairsArray
 * File Created: Sunday, 17th July 2022 9:19:26 am
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
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(k + 1, 0));
        int M = 1000000007;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    int val = (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return ((dp[n][k] + M - (k > 0 ? dp[n][k - 1] : 0)) % M);
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: n = 3, k = 0
    // Output: 1
    // Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
    // Input: n = 3, k = 1
    // Output: 2
    // Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
    return 0;
}