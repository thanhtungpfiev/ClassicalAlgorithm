/*
 * File: main.cpp
 * Project: RangeSumQueryImmutable
 * File Created: Friday, 3rd June 2022 2:38:57 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
    vector<int> m_nums;
    vector<int> dp;
    NumArray(vector<int> &nums)
    {
        m_nums = nums;
        dp = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i + 1] = dp[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        int result = dp[right + 1] - dp[left];
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main(int argc, char **argv)
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
