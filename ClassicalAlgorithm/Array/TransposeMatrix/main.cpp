/*
 * File: main.cpp
 * Project: TransposeMatrix
 * File Created: Monday, 18th July 2022 10:18:30 am
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
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> matrixTranspose(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                matrixTranspose[i][j] = matrix[j][i];
            }
        }
        return matrixTranspose;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [[1,4,7],[2,5,8],[3,6,9]]
    // Input: matrix = [[1,2,3],[4,5,6]]
    // Output: [[1,4],[2,5],[3,6]]
    return 0;
}