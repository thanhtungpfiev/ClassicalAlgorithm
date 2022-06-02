/*
 * File: main.cpp
 * Project: TransposeMatrix
 * File Created: Thursday, 2nd June 2022 1:37:23 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

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
    void print(const vector<vector<int>> &matrix) const
    {
        for (const auto &row : matrix)
        {
            for (const auto &col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<vector<int>>
        matrixTranspose = sl.transpose(matrix);
    sl.print(matrixTranspose);
    matrix = {{1, 2, 3}, {4, 5, 6}};
    matrixTranspose = sl.transpose(matrix);
    sl.print(matrixTranspose);
}