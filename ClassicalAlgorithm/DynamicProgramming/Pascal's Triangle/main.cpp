/*
 * File: main.cpp
 * Project: Pascal'sTriangle
 * File Created: Tuesday, 19th July 2022 11:21:36 am
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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> prev = result[i - 1];
            vector<int> r(i + 1, 0);
            r[0] = r[i] = 1;
            for (int j = 1; j < i; ++j)
            {
                r[j] = prev[j - 1] + prev[j];
            }
            result.push_back(r);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: numRows = 5
    // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    // Input: numRows = 1
    // Output: [[1]]
    return 0;
}