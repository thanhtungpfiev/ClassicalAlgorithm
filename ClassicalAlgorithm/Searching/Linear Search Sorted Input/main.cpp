/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/30/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool linearSearchSorted(vector<int> &data, int value)
{
    int size = data.size();
    for (int i = 0; i < size; ++i) {
        if (value == data[i]) {
            return true;
        } else if (value < data[i]) {
            return false;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << linearSearchSorted(v, 0) << endl;
    cout << linearSearchSorted(v, 5) << endl;
    return 0;
}
