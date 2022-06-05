/*
 * File: main.cpp
 * Project: PartitionArraySuchThatMaximumDifferenceIsK
 * File Created: Sunday, 5th June 2022 12:58:52 pm
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
    int partitionArray(vector<int> &nums, int k)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        int minIndex = 0;
        int maxIndex = 0;
        while (maxIndex < nums.size())
        {
            while (maxIndex < nums.size() && nums[maxIndex] - nums[minIndex] <= k)
            {
                maxIndex++;
            }
            result++;
            minIndex = maxIndex;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}