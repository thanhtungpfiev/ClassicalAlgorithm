/*
 * File: main.cpp
 * Project: MaximumErasureValue
 * File Created: Sunday, 12th June 2022 3:25:08 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int i = 0, j = 0, curr_sum = 0, max_sum = 0;
        unordered_set<int> ht;
        while (j < nums.size())
        {
            while (ht.find(nums[j]) != ht.end())
            {
                curr_sum -= nums[i];
                ht.erase(nums[i]);
                i++;
            }
            curr_sum += nums[j];
            ht.insert(nums[j]);
            j++;
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {4,2,4,5,6};
    cout << sl.maximumUniqueSubarray(nums) << endl;
    nums = {5,2,1,2,5,2,1,2,5};
    cout << sl.maximumUniqueSubarray(nums) << endl;
    return 0;
}