/*
 * File: main.cpp
 * Project: MinMaxGame
 * File Created: Sunday, 5th June 2022 11:51:29 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else
        {
            vector<int> newNums(nums.size() / 2);
            for (int i = 0; i < nums.size() / 2; ++i)
            {
                if (i % 2 == 0)
                {
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            return minMaxGame(newNums);
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {1,3,5,2,4,8,2,2};
    cout << sl.minMaxGame(nums) << endl;
    vector<int> nums2 = {3};
    cout << sl.minMaxGame(nums2) << endl;
    return 0;
}