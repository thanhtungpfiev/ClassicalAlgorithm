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
    vector<int> coins = {1, 3, 4};
    vector<int> count(n + 1);
    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (auto c : coins) {
            if (x-c >= 0) {
                count[x] += count[x-c];
            }
        }
    }
    cout << count[n] << endl;
    return 0;
}
