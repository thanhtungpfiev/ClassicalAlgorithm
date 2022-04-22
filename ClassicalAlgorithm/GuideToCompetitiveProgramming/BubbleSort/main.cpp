/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/22/2022
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
    vector<int> arr = {1, 3, 8, 2, 9, 2, 5, 6};
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (const auto e : arr) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
