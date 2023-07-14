/*
 * File: main.cpp
 * Project: RangeSumQuery2DImmutable
 * File Created: Friday, 3rd June 2022 2:17:18 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1));
        for (int r = 0; r < matrix.size(); ++r)
        {
            for (int c = 0; c < matrix[r].size(); ++c)
            {
                dp[r][c + 1] = dp[r][c] + matrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int result = 0;
        for (int r = row1; r <= row2; ++r)
        {
            result += dp[r][col2 + 1] - dp[r][col1];
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char **argv)
{
    vector<vector<int>> matrix = {{3, 0}, {5, 6}};
    NumMatrix numMatrix(matrix);
    cout << "Hello World" << endl;
    return 0;
}