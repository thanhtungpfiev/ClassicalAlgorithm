#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((i == j || i + j == n - 1))
                {
                    if (!grid[i][j])
                    {
                        return false;
                    }
                }
                else if (grid[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> grid = {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
    cout << sl.checkXMatrix(grid) << endl;
    grid = {{5,7,0},{0,3,1},{0,5,0}};
    cout << sl.checkXMatrix(grid) << endl;
    return 0;
}