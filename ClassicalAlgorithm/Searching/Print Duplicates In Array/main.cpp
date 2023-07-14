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
#include <algorithm>
#include <unordered_set>

using namespace std;

void printRepeating(vector<int> &data)
{
    for (int i = 0; i < data.size(); ++i) {
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[i] == data[j]) {
                cout << data[i] << " ";
            }
        }
    }
    cout << endl;
}

void printRepeating2(vector<int> &data)
{
    sort(data.begin(), data.end());
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] == data[i - 1]) {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}

void printRepeating3(vector<int> &data)
{
    unordered_set<int> hs;
    for (int i = 0; i < data.size(); ++i) {
        if (find(hs.begin(), hs.end(), data[i]) != hs.end()) {
            cout << data[i] << " ";
        } else {
            hs.insert(data[i]);
        }
    }
    cout << endl;
}

void printRepeating4(vector<int> &data)
{
    vector<int> count(data.size());
    for (int i = 0; i < data.size(); ++i) {
        if (count[i] == 1) {
            cout << data[i] << " ";
        } else {
            count[i]++;
        }
    }
    cout << endl;
}


int main()
{
    vector<int> v1 = {1, 2, 3, 6, 3, 6, 1};
    vector<int> v2 = {1, 2, 3, 4 ,3};
    printRepeating(v1);
    printRepeating(v2);
    printRepeating2(v1);
    printRepeating2(v2);
    printRepeating3(v1);
    printRepeating3(v2);
    return 0;
}
