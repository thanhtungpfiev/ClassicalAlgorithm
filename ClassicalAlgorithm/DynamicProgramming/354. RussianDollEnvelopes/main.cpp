/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/27/2022
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

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> lis;
        for (int i = 0; i < envelopes.size(); ++i) {
            int currentVal = envelopes[i][1];
            auto it = lower_bound(lis.begin(), lis.end(), currentVal);
            if (it != lis.end()) {
                *it = currentVal;
            } else {
                lis.push_back(currentVal);
            }
        }
        return lis.size();
    }
};

int main()
{
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    Solution sl;
    cout << sl.maxEnvelopes(envelopes) << endl;
    envelopes = {{1,1},{1,1},{1,1}};
    cout << sl.maxEnvelopes(envelopes) << endl;
    return 0;
}
