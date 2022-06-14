/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/10/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generator(int st, int k, int n, vector<vector<int>>& ans, vector<int>& ds) {
        if (k == 0) {
            if (n == 0) {
                ans.push_back(ds);
                return;
            }
        }
        for (int i = st; i <= 9; ++i) {
            ds.push_back(i);
            generator(i + 1, k - 1, n - i, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        generator(1, k, n, ans, ds);
        return ans;
    }
};

int main()
{
    Solution s;
    int k = 3, n = 7;
    vector<vector<int>> ans = s.combinationSum3(k, n);
    k = 3; n = 9;
    ans = s.combinationSum3(k, n);
    k = 4; n = 1;
    ans = s.combinationSum3(k, n);
    return 0;
}
