/*
 * File: main.cpp
 * Project: FindPivotIndex
 * File Created: Monday, 18th July 2022 11:24:24 am
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
    int pivotIndex(vector<int> &nums)
    {
        int index = -1;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i < sums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sums[i] == sums[sums.size() - 1] - sums[i] - nums[i])
            {
                index = i;
                break;
            }
        }
        return index;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1;
        int sum = 0, leftsum = 0;
        for (auto e : nums) {
            sum += e;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i]) {
                index = i;
                break;
            }
            leftsum += nums[i];
        }
        return index;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: nums = [1,7,3,6,5,6]
    // Output: 3
    // Explanation:
    // The pivot index is 3.
    // Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    // Right sum = nums[4] + nums[5] = 5 + 6 = 11
    // Input: nums = [1,2,3]
    // Output: -1
    // Explanation:
    // There is no index that satisfies the conditions in the problem statement.
    // Input: nums = [2,1,-1]
    // Output: 0
    // Explanation:
    // The pivot index is 0.
    // Left sum = 0 (no elements to the left of index 0)
    // Right sum = nums[1] + nums[2] = 1 + -1 = 0
    return 0;
}