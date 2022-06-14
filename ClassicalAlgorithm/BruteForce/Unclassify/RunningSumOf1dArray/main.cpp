/*
 * File: main.cpp
 * Project: RunningSumOf1dArray
 * File Created: Wednesday, 1st June 2022 5:01:54 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
    void print(const vector<int> &nums) const
    {
        for (const auto &i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {1, 2, 3, 4};
    sl.runningSum(nums);
    sl.print(nums);
    nums = {1, 1, 1, 1, 1};
    sl.runningSum(nums);
    sl.print(nums);
    nums = {3, 1, 2, 10, 1};
    sl.runningSum(nums);
    sl.print(nums);
}
