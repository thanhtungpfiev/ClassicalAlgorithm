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

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}
