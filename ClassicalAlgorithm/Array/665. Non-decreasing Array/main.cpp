/*
 * File: main.cpp
 * Project: Non-decreasingArray
 * File Created: Saturday, 25th June 2022 9:10:05 am
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
    bool checkPossibility(vector<int> &nums)
    {
        for (int i = 1, err = 0; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (err++ || i > 1 && i < nums.size() - 1 && nums[i - 2] > nums[i] && nums[i - 1] > nums[i + 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {4,2,3};
    cout << sl.checkPossibility(nums) << endl;
    nums = {4,2,1};
    cout << sl.checkPossibility(nums) << endl;
    return 0;
}