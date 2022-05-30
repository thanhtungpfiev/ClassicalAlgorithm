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
#include <unordered_map>

using namespace std;

int getMax(vector<int> &data)
{
    int max = data[0], cnt = 1, max_cnt = 1;
    for (int i = 1; i < data.size(); ++i) {
        cnt = 1;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[i] == data[j]) {
                cnt++;
            }
        }
        if (cnt > max_cnt) {
            max_cnt = max;
            max = data[i];
        }
    }
    return max;
}

int getMax2(vector<int> &data)
{
    int max = data[0], max_cnt = 1;
    int curr = data[0], curr_cnt = 1;
    sort(data.begin(), data.end());
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] == data[i - 1]) {
            curr_cnt++;
        } else {
            curr_cnt = 1;
            curr = data[i];
        }
        if (curr_cnt > max_cnt) {
            max_cnt = curr_cnt;
            max = data[i];
        }
    }
    return max;
}

int getMax3(vector<int> &data)
{
    unordered_map<int, int> m;
    for (int i = 0; i < data.size(); ++i) {
        m[data[i]]++;
    }
    int max = 0, max_cnt = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > max_cnt) {
            max = it->first;
            max_cnt = it->second;
        }
    }
    return max;
}

int getMax4(vector<int> &data, int range)
{
    vector<int> cnt(range);
    int max = data[0], max_cnt = 1;
    for (int i = 0; i < data.size(); ++i) {
        cnt[data[i]]++;
        if (cnt[data[i]] > max_cnt) {
            max = data[i];
            max_cnt = cnt[data[i]];
        }
    }
    return max;
}

int main()
{
    vector<int> v1 = {1, 3, 2, 1, 4, 1};
    vector<int> v2 = {10, 20, 10, 20, 30, 20, 20};
//    cout << getMax(v1) << endl;
//    cout << getMax(v2) << endl;
//    cout << getMax2(v1) << endl;
//    cout << getMax2(v2) << endl;
    cout << getMax3(v1) << endl;
    cout << getMax3(v2) << endl;
    cout << getMax4(v1, 5) << endl;
    cout << getMax4(v2, 31) << endl;
    return 0;
}
