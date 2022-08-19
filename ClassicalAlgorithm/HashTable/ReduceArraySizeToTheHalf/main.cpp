/*
 * File: main.cpp
 * Project: ReduceArraySizeToTheHalf
 * File Created: Thursday, 18th August 2022 10:49:50 am
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
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> ht;
        int n = arr.size();
        for (auto e : arr)
        {
            ht[e]++;
        }
        priority_queue<int> pq;
        for (auto it : ht)
        {
            pq.push(it.second);
        }
        int cnt = 0, k = 0;
        while (!pq.empty())
        {
            k += pq.top();
            pq.pop();
            ++cnt;
            if (k >= n / 2)
            {
                return cnt;
            }
        }
        return cnt;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: arr = [3,3,3,3,5,5,5,2,2,7]
    // Output: 2
    // Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
    // Possible sets of size 2 are {3,5},{3,2},{5,2}.
    // Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

    // Input: arr = [7,7,7,7,7,7]
    // Output: 1
    // Explanation: The only possible set you can choose is {7}. This will make the new array empty.
    return 0;
}