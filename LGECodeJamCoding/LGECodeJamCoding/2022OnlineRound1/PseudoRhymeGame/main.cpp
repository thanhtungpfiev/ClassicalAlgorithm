/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 25 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while (T --> 0) {
        int n = 0, L = 0, F = 0;
        cin >> n >> L >> F;
        string str = "";
        map<string, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            if (str.length() >= F) {
                m[str.substr(str.length() - F)] += 1;
            }
        }
        int result = 0;
        for (auto const& [key, val] : m) {
            result += val / 2;
        }
        cout << result << endl;
    }
    return 0;
}
