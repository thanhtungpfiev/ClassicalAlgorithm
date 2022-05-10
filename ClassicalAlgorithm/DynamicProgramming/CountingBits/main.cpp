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
    unsigned int countSetBits(unsigned int n)
    {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
    vector<int> countBits2(int n) {
        vector<int> ans;
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i] += dp[i / 2] + i % 2;
            ans.push_back(dp[i]);
        }
        return ans;
    }

};

int main()
{
    Solution s;
    int n = 2;
    vector<int> a = s.countBits(n);
    n = 5;
    a = s.countBits(n);
    return 0;
}
