/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/9/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int dpWithoutRecursive(int n)
{
    vector<vector<int>> F(n + 1, vector<int>(n + 1));
    F[0][0] = 1;
    for (int m = 1; m <= n; ++m) {
        for (int v = 0; v <= n; ++v) {
            if (v < m) {
                F[m][v] = F[m - 1][v];
            } else {
                F[m][v] = F[m - 1][v] + F[m][v - m];
            }
        }
    }
    return F[n][n];
}

int dpWithRecursive(int n, int m, int v)
{
    if (m == 0) {
        if (v == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (v < m) {
            return dpWithRecursive(n, m - 1, v);
        } else {
            return dpWithRecursive(n, m - 1, v) + dpWithRecursive(n, m, v - m);
        }
    }
}

int dpWithRecursiveImprove(int m, int v, vector<vector<int>>& F)
{
    if (F[m][v] != - 1) return F[m][v];
    if (m == 0) {
        if (v == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (v < m) {
            return dpWithRecursiveImprove(m - 1, v, F);
        } else {
            return dpWithRecursiveImprove(m - 1, v, F) + dpWithRecursiveImprove(m, v - m, F);
        }
    }
}
int main()
{
    int n = 5;

    cout << dpWithoutRecursive(n) << endl;
    cout << dpWithRecursive(n, n, n) << endl;

    vector<vector<int>> F(n + 1, vector<int>(n + 1, -1));
    cout << dpWithRecursiveImprove(n, n, F) << endl;

    return 0;
}
