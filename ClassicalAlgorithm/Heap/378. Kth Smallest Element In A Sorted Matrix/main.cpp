/*
 * File: main.cpp
 * Project: KthSmallestElementInASortedMatrix
 * File Created: Tuesday, 2nd August 2022 10:17:08 am
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
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pq.size() < k)
                {
                    pq.push(matrix[i][j]);
                }
                else
                {
                    if (matrix[i][j] < pq.top())
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    // Output: 13
    // Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

    // Input: matrix = [[-5]], k = 1
    // Output: -5

    return 0;
}