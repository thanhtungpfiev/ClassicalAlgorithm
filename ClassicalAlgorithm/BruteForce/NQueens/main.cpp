/*
 * File: main.cpp
 * Project: NQueens
 * File Created: Saturday, 4th June 2022 7:08:05 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void search(int y, int n, vector<vector<string>> &result, vector<int> &col, vector<int> &diag1, vector<int> &diag2, vector<int> &position)
    {
        if (y == n)
        {
            vector<string> tempV;
            for (const auto &e : position)
            {
                string tempS(n, '.');
                tempS[e] = 'Q';
                tempV.push_back(tempS);
            }
            result.push_back(tempV);
            return;
        }
        for (int x = 0; x < n; x++)
        {
            if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
                continue;
            col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
            position[y] = x;
            search(y + 1, n, result, col, diag1, diag2, position);
            col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<int> col(n);
        vector<int> diag1(2 * n);
        vector<int> diag2(2 * n);
        vector<int> position(n);
        search(0, n, result, col, diag1, diag2, position);
        return result;
    }
    void print(const vector<vector<string>> &result)
    {
        for (const auto &row : result)
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
    int n = 4;
    vector<vector<string>> result = sl.solveNQueens(n);
    sl.print(result);
    n = 1;
    result = sl.solveNQueens(n);
    sl.print(result);
    return 0;
}