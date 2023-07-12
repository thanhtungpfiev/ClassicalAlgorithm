/*
 * File: main.cpp
 * Project: MinimumMovesToEqualArrayElementsII
 * File Created: Thursday, 30th June 2022 11:47:06 am
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
    int minMoves2(vector<int> &nums)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        for (int i = 0; i < nums.size(); ++i)
        {
            result += abs(nums[i] - median);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: nums = [1,2,3]
    // Output: 2
    // Input: nums = [1,10,2,9]
    // Output: 16
    // Take the case [1,0,0,8,6] for example, when you use median 1 instead of mean 3, 1,0 and 0 saves 2x3=6 moves, while 8 and 6 has 2x2=4 more move.
    // Usually, minimized absolute differences => median; minimized squared differences => mean.

    return 0;
}