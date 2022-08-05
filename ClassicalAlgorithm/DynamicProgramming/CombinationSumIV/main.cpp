/*
 * File: main.cpp
 * Project: CombinationSumIV
 * File Created: Friday, 5th August 2022 11:14:29 am
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
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<uint> table(target + 1);
        table[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            for (auto &num : nums)
            {
                if (i >= num)
                {
                    table[i] += table[i - num];
                }
            }
        }
        return table[target];
    }
};

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (dp[target] != -1)
        {
            return dp[target];
        }
        dp[target] = 0;
        for (auto num : nums)
        {
            if (num <= target)
            {
                dp[target] += combinationSum4(nums, target - num, dp);
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return combinationSum4(nums, target, dp);
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: nums = [1,2,3], target = 4
    // Output: 7
    // Explanation:
    // The possible combination ways are:
    // (1, 1, 1, 1)
    // (1, 1, 2)
    // (1, 2, 1)
    // (1, 3)
    // (2, 1, 1)
    // (2, 2)
    // (3, 1)
    // Note that different sequences are counted as different combinations.

    // Input: nums = [9], target = 3
    // Output: 0
    return 0;
}