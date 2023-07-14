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

void generate(int step, vector<int>& v)
{
    if (step == v.size()) {
        for (const auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 2; ++i) {
        v[step] = i;
        generate(step + 1, v);
    }
}

int main()
{
    int n = 3;
    vector<int> v(n);
    generate(0, v);
    return 0;
}
