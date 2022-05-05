/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/16/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sequenceSearch(const vector<int>& v, const int& key) {
    int result = -1;
    for (int i  = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            result = i;
            break;
        }
    }
    return result;
}

int binarySearch(const vector<int>& v, const int& key) {
    int result = -1;
    int start = 0;
    int end = v.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == key) {
            result = mid;
            break;
        } else if (v[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    std::vector<int> v = {5, 2, 3, 8, 9};
    cout << sequenceSearch(v, 1) << endl;
    cout << sequenceSearch(v, 5) << endl;
    cout << sequenceSearch(v, 3) << endl;
    cout << sequenceSearch(v, 9) << endl;

   std::sort(v.begin(), v.end());
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
    cout << binarySearch(v, 1) << endl;
    cout << binarySearch(v, 5) << endl;
    cout << binarySearch(v, 3) << endl;
    cout << binarySearch(v, 9) << endl;
    return 0;
}
