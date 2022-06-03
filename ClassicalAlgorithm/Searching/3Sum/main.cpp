/*
 * File: main.cpp
 * Project: 3Sum
 * File Created: Friday, 3rd June 2022 5:30:13 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> output;
        vector<vector<int>> final;
        if (nums.size() < 3)
        {
            return final;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else
                {
                    output.insert({nums[i], nums[l++], nums[r]});
                }
            }
        }
        for (auto i : output)
        {
            final.push_back(i);
        }

        return final;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sl.threeSum(nums);
    return 0;
}