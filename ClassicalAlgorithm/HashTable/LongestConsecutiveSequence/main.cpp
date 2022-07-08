/*
 * File: main.cpp
 * Project: LongestConsecutiveSequence
 * File Created: Tuesday, 5th July 2022 5:10:59 pm
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
    int longestConsecutive(vector<int> &nums)
    {
        int result = 0;
        unordered_set<int> ht(nums.begin(), nums.end());
        for (auto num : nums)
        {
            if (ht.find(num - 1) != ht.end())
                continue;
            int currNum = num;
            int currStreak = 0;
            while (ht.find(currNum) != ht.end())
            {
                ++currNum;
                ++currStreak;
            }
            result = max(result, currStreak);
        }
        return result;
    }
};

class Solution2
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        if (nums.size() == 1)
            return 1;
        sort(nums.begin(), nums.end());
        int result = 0, streak = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1)
                streak++;
            else
            {
                result = max(result, streak);
                streak = 1;
            }
        }
        result = max(result, streak);
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    // Input: nums = [0,3,7,2,5,8,4,6,0,1]
    // Output: 9
    return 0;
}