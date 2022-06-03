/*
 * File: main.cpp
 * Project: SearchingForAnElementInA2DSortedArray
 * File Created: Friday, 3rd June 2022 4:01:59 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

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
                c--;
            }
            else
            {
                r++;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << sl.searchMatrix(matrix, target) << endl;
    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    target = 13;
    cout << sl.searchMatrix(matrix, target) << endl;
    return 0;
}