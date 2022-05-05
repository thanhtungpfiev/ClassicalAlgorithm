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
    vector<int> weights = {1, 3, 3, 5};
    int n = 0;
    for (auto w : weights) {
        n += w;
    }
    vector<vector<int>> possible(weights.size() + 1, vector<int>(n + 1));
    possible[0][0] = 1;
    for (int k = 1; k <= weights.size(); ++k) {
        for (int x = 0; x <= n; ++x) {
            if (x - weights[k - 1] >= 0) {
                possible[k][x] |= possible[k - 1][x - weights[k - 1]];
            }
            possible[k][x] |= possible[k - 1][x];
        }
    }
    cout << possible[0][0] << endl;
    cout << possible[1][1] << " " << possible[2][2] << endl;
    return 0;
}
