/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/31/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool FindPair(std::vector<int> &data, int value)
{
    for (int i = 0; i < data.size(); ++i) {
        for(int j = i + 1; j < data.size(); ++j) {
            if (data[i] + data[j] == value) {
                return true;
            }
        }
    }
    return false;
}

bool FindPair2(std::vector<int> &data, int value)
{
    sort(data.begin(), data.end());
    int first = 0, second = data.size() - 1;
    while (first < second) {
        if (data[first] + data[second] == value) {
            return true;
        } else if (data[first] + data[second] < value) {
            first++;
        } else {
            second--;
        }
    }
    return false;
}

bool FindPair3(std::vector<int> &data, int value)
{
    unordered_set<int> ht;
    for (int i = 0; i < data.size(); ++i) {
        if (find(ht.begin(), ht.end(), value - data[i]) != ht.end()) {
            return true;
        }
        ht.insert(data[i]);
    }
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
