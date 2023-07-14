/*
 * File: main.cpp
 * Project: TwoSum
 * File Created: Sunday, 14th August 2022 11:36:24 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); ++i)
        {
            int temp = target - nums[i];
            if (ht.find(temp) != ht.end())
            {
                return {ht[temp], i};
            }
            ht[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    // Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]
    // Input: nums = [3,3], target = 6
    // Output: [0,1]
    return 0;
}