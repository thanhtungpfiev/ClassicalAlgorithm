/*
 * File: main.cpp
 * Project: SpiralMatrix
 * File Created: Wednesday, 17th August 2022 10:59:45 am
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
    enum DIRECTION
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, right = m - 1, bottom = n - 1, left = 0;
        DIRECTION direction = RIGHT;
        while (top <= bottom && left <= right)
        {
            if (direction == RIGHT)
            {
                for (int i = left; i <= right; ++i)
                {
                    result.push_back(matrix[top][i]);
                }
                ++top;
                direction = DOWN;
            }
            else if (direction == DOWN)
            {
                for (int i = top; i <= bottom; ++i)
                {
                    result.push_back(matrix[i][right]);
                }
                --right;
                direction = LEFT;
            }
            else if (direction == LEFT)
            {
                for (int i = right; i >= left; --i)
                {
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;
                direction = UP;
            }
            else if (direction == UP)
            {
                for (int i = bottom; i >= top; --i)
                {
                    result.push_back(matrix[i][left]);
                }
                ++left;
                direction = RIGHT;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,3,6,9,8,7,4,5]

    // Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    return 0;
}