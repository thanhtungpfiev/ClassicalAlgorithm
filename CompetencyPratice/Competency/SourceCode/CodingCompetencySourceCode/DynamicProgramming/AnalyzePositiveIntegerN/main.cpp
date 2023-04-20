/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/24/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int normal(int n)
{
    int result = 1;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    arr[0][0] = 1;
    for (int m = 1; m <= n; m++) {
        for (int v = 0; v <= n; v++) {
            if (v < m) {
                arr[m][v] = arr[m - 1][v];
            } else {
                arr[m][v] = arr[m - 1][v] + arr[m][v - m];
            }
        }
    }
    result = arr[n][n];
    return result;
}

int getF(vector<vector<int>>& arr, int m, int v)
{
    if (arr[m][v] != -1) {
        return arr[m][v];
    }
    if (m == 0) {
        if (v == 0)
        {
            arr[m][v] = 1;
        } else {
            arr[m][v] = 0;
        }
    } else {
        if (v < m) {
            arr[m][v] = getF(arr, m -1, v);
        } else {
            arr[m][v] = getF(arr, m - 1, v) + getF(arr, m, v - m);
        }
    }
    return arr[m][v];
}

int recursive(int n) {
    int result = 1;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, -1));
    getF(arr, n, n);
    result = arr[n][n];
    return result;
}

int main()
{
    int n = 5;

    cout << recursive(n) << endl;
    return 0;
}
