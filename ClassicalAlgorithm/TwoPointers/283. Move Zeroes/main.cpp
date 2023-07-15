/*
 * File: main.cpp
 * Project: 283. Move Zeroes
 * File Created: Saturday, 15th July 2023 4:42:16 pm
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
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); ++j)
        {
            nums[j] = 0;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}