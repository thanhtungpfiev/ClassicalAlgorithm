/*
 * File: main.cpp
 * Project: SearchA2DMatrix
 * File Created: Wednesday, 24th August 2022 1:41:24 pm
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0, c = n - 1;
        while (r < m && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] > target)
            {
                --c;
            }
            else
            {
                ++r;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // Output: true

    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    // Output: false
    return 0;
}