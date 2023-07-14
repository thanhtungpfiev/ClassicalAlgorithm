/*
 * File: main.cpp
 * Project: SearchInSortedRotatedArray
 * File Created: Thursday, 2nd June 2022 5:48:03 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    int binarSearch(vector<int> &nums, int start, int end, int target)
    {
        int result = -1;
        if (start < 0 || end >= nums.size())
        {
        }
        else
        {
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (nums[mid] == target)
                {
                    result = mid;
                    break;
                }
                else if (nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return result;
    }

    int search(vector<int> &nums, int target)
    {
        int result = -1;
        int size = nums.size();
        if (size > 0)
        {
            int index = -1;
            int start = 0;
            int end = size - 1;
            // find pivot by binary search
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (nums[mid] > nums[size - 1])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                    index = mid;
                }
            }
            // find target in 2 arrays
            if (target == nums[index])
            {
                result = index;
            }
            else if (target > nums[size - 1])
            {
                result = binarSearch(nums, 0, index - 1, target);
            }
            else
            {
                result = binarSearch(nums, index, size - 1, target);
            }
        }
        return result;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int result = -1;
        int start = 0, end = nums.size() - 1, index = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[nums.size() - 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                index = mid;
            }
        }
        cout << index << endl; //  find the index of the smallest value using binary search.
        if (target == nums[index])
        {
            result = index;
        }
        else if (target > nums[nums.size() - 1])
        {
            auto it = lower_bound(nums.begin(), nums.begin() + index, target);
            if (it != nums.end() && (*it == target))
            {
                result = distance(nums.begin(), it);
            }
        }
        else
        {
            auto it = lower_bound(nums.begin() + index, nums.end(), target);
            if (it != nums.end() && (*it == target))
            {
                result = distance(nums.begin(), it);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;

    // Input: nums = [4,5,6,7,0,1,2], target = 0
    // Output: 4

    // Input: nums = [4,5,6,7,0,1,2], target = 3
    // Output: -1

    // Input: nums = [1], target = 0
    // Output: -1
    return 0;
}
