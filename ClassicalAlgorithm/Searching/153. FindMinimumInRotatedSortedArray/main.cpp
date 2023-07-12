/*
 * File: main.cpp
 * Project: FindMinimumInRotatedSortedArray
 * File Created: Sunday, 5th June 2022 9:22:08 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int l = 0, r = nums.size() - 1;
        if (nums[r] > nums[0])
        {
            return nums[0];
        }
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            if (nums[mid] > nums[0])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {11, 13, 15, 17};
    cout << sl.findMin(nums) << endl;
    nums = {3, 4, 5, 1, 2};
    cout << sl.findMin(nums) << endl;
    return 0;
}