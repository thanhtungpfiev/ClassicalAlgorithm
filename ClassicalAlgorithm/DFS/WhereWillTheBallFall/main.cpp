/*
 * File: main.cpp
 * Project: WhereWillTheBallFall
 * File Created: Wednesday, 17th August 2022 1:36:50 pm
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
    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> result;
        int m = grid.size();
        int n = grid[0].size();
        for (int j = 0; j < n; ++j)
        {
            int row = 0, col = j;
            while (row < m)
            {
                if (grid[row][col] == 1)
                {
                    if (col + 1 >= n || grid[row][col + 1] == -1)
                    {
                        result.push_back(-1);
                        break;
                    }
                    ++col;
                }
                else
                {
                    if (col - 1 < 0 || grid[row][col - 1] == 1)
                    {
                        result.push_back(-1);
                        break;
                    }
                    --col;
                }
                ++row;
            }
            if (row == m)
            {
                result.push_back(col);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
    // Output: [1,-1,-1,-1,-1]
    // Explanation: This example is shown in the photo.
    // Ball b0 is dropped at column 0 and falls out of the box at column 1.
    // Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
    // Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
    // Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
    // Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.

    // Input: grid = [[-1]]
    // Output: [-1]
    // Explanation: The ball gets stuck against the left wall.

    // Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
    // Output: [0,1,2,3,4,-1]
    return 0;
}