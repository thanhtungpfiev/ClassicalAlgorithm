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

void k_string(int n, int k, vector<int>& v)
{
    if (n < 1) {
        for (auto const &e : v) {
            cout << e << " ";
        }
        cout << endl;
    } else {
        for (int j = 0; j < k; ++j) {
            v[n - 1] = j;
            k_string(n - 1, k, v);
        }
    }
}

int main()
{
    int n = 5, k = 3;
    // cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    k_string(n, k, v);
    return 0;
}
