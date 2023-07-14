/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/5/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5;
    vector<vector<int>> square = {{3, 7, 9, 2, 7},
                                  {9, 8, 3, 5, 5},
                                  {1, 7, 9, 8, 5},
                                  {3, 8, 6, 4, 10},
                                  {6, 3, 9, 7, 8}};
    vector<vector<int>> sum(n + 1, vector<int>(n + 1));
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            sum[x][y] = max(sum[x][y - 1], sum[x - 1][y]) + square[x - 1][y - 1];
        }
    }
    cout << sum[n][n] << endl;
    return 0;
}
