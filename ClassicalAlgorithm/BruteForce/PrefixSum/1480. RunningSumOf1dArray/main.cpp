/*
 * File: main.cpp
 * Project: RunningSumOf1dArray
 * File Created: Monday, 18th July 2022 10:15:40 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

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
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: nums = [1,2,3,4]
    // Output: [1,3,6,10]
    // Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
    // Input: nums = [1,1,1,1,1]
    // Output: [1,2,3,4,5]
    // Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
    // Input: nums = [3,1,2,10,1]
    // Output: [3,4,6,16,17]
    return 0;
}