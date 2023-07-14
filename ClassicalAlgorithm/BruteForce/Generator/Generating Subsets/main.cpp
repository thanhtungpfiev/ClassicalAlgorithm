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

void search(int step, int n, vector<int>& subset)
{
    if (step == n + 1) {
        for (const auto & e : subset) {
            cout << e << " ";
        }
        cout << endl;
        return;
    }
    subset.push_back(step);
    search(step + 1, n, subset);
    subset.pop_back();
    search(step + 1, n, subset);
}

int main()
{
    int n = 3;
    cin >> n;
    vector<int> subset;
    search(1, n, subset);
    return 0;
}
