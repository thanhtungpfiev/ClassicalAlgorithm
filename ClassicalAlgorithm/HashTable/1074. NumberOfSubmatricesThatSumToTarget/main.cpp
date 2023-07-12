/*
 * File: main.cpp
 * Project: NumberOfSubmatricesThatSumToTarget
 * File Created: Monday, 18th July 2022 9:11:37 am
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
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int result = 0;
        int row = matrix.size();
        int column = matrix[0].size() + 1;
        vector<vector<int>> sum(row, vector<int>(column, 0));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 1; j < column; ++j)
            {
                sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
            }
        }

        for (int start = 0; start < column; ++start)
        {
            for (int end = start + 1; end < column; ++end)
            {
                int sumOfSubMatrix = 0;
                unordered_map<int, int> ht;
                ht[0] = 1;
                for (int r = 0; r < row; ++r)
                {
                    sumOfSubMatrix += sum[r][end] - sum[r][start];
                    if (ht.find(sumOfSubMatrix - target) != ht.end())
                    {
                        result += ht[sumOfSubMatrix - target];
                    }
                    ht[sumOfSubMatrix]++;
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
    // Output: 4
    // Explanation: The four 1x1 submatrices that only contain 0.
    // Input: matrix = [[1,-1],[-1,1]], target = 0
    // Output: 5
    // Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
    // Input: matrix = [[904]], target = 0
    // Output: 0
    return 0;
}