/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/26/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool isArrayInSortedOrder(vector<int>& v)
{
    if (v.size() == 0 || v.size() == 1) {
        return true;
    }
    if (v[v.size() - 1] < v[v.size() - 2]) {
        return false;
    } else {
        v.pop_back();
        return isArrayInSortedOrder(v);
    }
}

int main()
{
    vector<int> v = {1, 2, 1};
    cout << isArrayInSortedOrder(v) << endl;
    return 0;
}
