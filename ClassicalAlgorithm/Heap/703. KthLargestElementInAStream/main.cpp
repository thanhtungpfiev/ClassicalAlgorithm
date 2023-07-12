/*
 * File: main.cpp
 * Project: KthLargestElementInAStream
 * File Created: Monday, 18th July 2022 2:58:46 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int m_k;
    KthLargest(int k, vector<int> &nums)
    {
        m_k = k;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pq.size() < k)
            {
                pq.push(nums[i]);
            }
            else
            {
                if (nums[i] > pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }

    int add(int val)
    {
        int result = 0;
        if (pq.size() < m_k)
        {
            pq.push(val);
            result = pq.top();
        }
        else
        {
            if (val > pq.top())
            {
                pq.pop();
                pq.push(val);
                result = pq.top();
            }
            else
            {
                result = pq.top();
            }
        }
        return result;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char **argv)
{
    Solution sl;
    // Input
    // ["KthLargest", "add", "add", "add", "add", "add"]
    // [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
    // Output
    // [null, 4, 5, 5, 8, 8]

    // Explanation
    // KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
    // kthLargest.add(3);   // return 4
    // kthLargest.add(5);   // return 5
    // kthLargest.add(10);  // return 5
    // kthLargest.add(9);   // return 8
    // kthLargest.add(4);   // return 8
    return 0;
}