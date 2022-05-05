/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/21/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void search(int y, int n, int& count, vector<int>& col, vector<int>& diag1, vector<int>& diag2, vector<int>& position)
{
    if (y == n) {
        count++;
        for (const auto e : position) {
            cout << e << " ";
        }
        cout << endl;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        position[y] = x;
        search(y + 1, n, count, col, diag1, diag2, position);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main()
{
    int n = 4;
    int count = 0;
    vector<int> col(n);
    vector<int> diag1(2 * n);
    vector<int> diag2(2 * n);
    vector<int> position(n);
    search(0, n, count, col, diag1, diag2, position);
    cout << count << endl;
    return 0;
}
