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

bool linearSearchUnsorted(vector<int> &data, int value)
{
    int size = data.size();
    for (int i = 0; i < size; ++i) {
        if (value == data[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1, 9, 7, 5};
    cout << linearSearchUnsorted(v, 0) << endl;
    cout << linearSearchUnsorted(v, 7) << endl;
    return 0;
}
