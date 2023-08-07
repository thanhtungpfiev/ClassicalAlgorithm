/*
 * File: main.cpp
 * Project: 215. Kth Largest Element in an Array
 * File Created: Monday, 31st July 2023 2:22:06 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}