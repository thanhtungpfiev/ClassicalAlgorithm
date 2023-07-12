/*
 * File: main.cpp
 * Project: WiggleSubsequence
 * File Created: Sunday, 3rd July 2022 10:54:12 am
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
    int wiggleMaxLength(vector<int> &nums)
    {
        vector<int> up(nums.size());
        vector<int> down(nums.size());
        up[0] = down[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[nums.size() - 1], down[nums.size() - 1]);
    }
};

int main(int argc, char **argv)
{
    // Input: nums = [1,7,4,9,2,5]
    //  Output: 6
    //  Input: nums = [1,17,5,10,13,15,10,5,16,8]
    //  Output: 7
    //  Input: nums = [1,2,3,4,5,6,7,8,9]
    //  Output: 2
    Solution sl;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << sl.wiggleMaxLength(nums) << endl;
    nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << sl.wiggleMaxLength(nums) << endl;
    nums = {1,2,3,4,5,6,7,8,9};
    cout << sl.wiggleMaxLength(nums) << endl;
    return 0;
}