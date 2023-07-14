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

using namespace std;

int getMajority(vector<int> &data)
{
    int max = data[0], cnt = 1, max_cnt = 1;
    for (int i = 0; i < data.size(); ++i) {
        cnt = 1;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[i] == data[j]) {
                cnt++;
            }
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
            max = data[i];
        }
    }
    if (max_cnt > data.size() / 2) {
        return max;
    } else {
        return 0;
    }
}

int getMajority2(vector<int> &data)
{
    int majIndex = data.size() / 2, count = 0;
    sort(data.begin(), data.end());
    int candidate = data[majIndex];
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == candidate) {
            count++;
        }
    }
    if (count > data.size() / 2) {
        return candidate;
    } else {
        return 0;
    }
}

int getMajority3(vector<int> &data)
{
    int candidate = data[0], cnt = 1;
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] == candidate) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt == 0) {
            candidate = data[i];
            cnt = 1;
        }
    }
    cnt = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == candidate) {
            cnt++;
        }
    }
    if (cnt > data.size() / 2) {
        return candidate;
    } else {
        return 0;
    }
}

int main()
{
    vector<int> nums1 = {3,2,3};
    vector<int> nums2 = {2,2,1,1,1,2,2};
    //    cout << getMajority(nums1) << endl;
    //    cout << getMajority(nums2) << endl;
    //    cout << getMajority2(nums1) << endl;
    //    cout << getMajority2(nums2) << endl;
    cout << getMajority3(nums1) << endl;
    cout << getMajority3(nums2) << endl;
    return 0;
}
