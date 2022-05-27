/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/27/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void findMaxBlock(const vector<vector<int>>& arr, int r, int c, int rmax, int colmax, int size, vector<vector<bool>>& cntarr, int &maxsize)
{
    if ((r >= rmax) || (c >= colmax)) {
        return;
    }
    cntarr[r][c] = true;
    size++;
    if (size > maxsize) {
        maxsize = size;
    }

    vector<vector<int>> direction = {
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
        {1, 0}, {1, 1}, {0, 1}, {-1, 1}
    };

    for (int i = 0; i < 8; i++) {
        int newi = r + direction[i][0];
        int newj = c + direction[i][1];
        if (newi < 0 || newi >= rmax || newj < 0 || newj >= colmax) {
            continue;
        }
        if (arr[newi][newj] == 1 && cntarr[newi][newj] == false) {
            findMaxBlock(arr, newi, newj, rmax, colmax, size, cntarr, maxsize);
        }
    }
    cntarr[r][c] = false;
}

int getMaxOnes(const vector<vector<int>>& arr, int rmax, int colmax)
{
    int maxsize = 0;
    vector<vector<bool>> cntarr(rmax, vector<bool>(colmax));
    for (int i = 0; i < rmax; ++i) {
        for (int j = 0; j < colmax; ++j) {
            if (arr[i][j] == 1) {
                findMaxBlock(arr, i, j, rmax, colmax, 0, cntarr, maxsize);
            }
        }
    }
    return maxsize;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0 ,1, 1}
    };
    cout << getMaxOnes(arr, 5, 5) << endl;
    return 0;
}
