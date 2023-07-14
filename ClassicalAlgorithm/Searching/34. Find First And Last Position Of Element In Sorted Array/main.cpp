/*
 * File: main.cpp
 * Project: FindFirstAndLastPositionOfElementInSortedArray
 * File Created: Sunday, 5th June 2022 8:48:14 am
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        if (nums.size() == 1)
        {
            if (target == nums[0])
            {
                return {0, 0};
            }
            else
            {
                return {-1, -1};
            }
        }
        nums.push_back(1000000001);
        auto it_first = lower_bound(nums.begin(), nums.end(), target);
        auto it_last = upper_bound(nums.begin(), nums.end(), target);
        if (it_first != nums.end() && it_last != nums.end() && *it_first == target && *(it_last - 1) == target)
        {
            int firstIndex = it_first - nums.begin();
            int lastIndex = it_last - nums.begin() - 1;
            return {firstIndex, lastIndex};
        }
        else
        {
            return {-1, -1};
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    nums = {};
    target = 0;
    return 0;
}
