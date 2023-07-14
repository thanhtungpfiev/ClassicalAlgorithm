/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 23 - 5 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(int i, int zeroes, int ones, vector<string>& strs, int& maxZeroes, int& maxOnes, vector<vector<vector<int> > >& dp) {
        if (i >= strs.size()) {
            return 0;
        }
        if (zeroes > maxZeroes || ones > maxOnes) {
            return 0;
        }
        if (dp[i][zeroes][ones] != -1) {
            return dp[i][zeroes][ones];
        }
        int zero = count(strs[i].begin(), strs[i].end(), '0');
        int one = strs[i].length() - zero;
        int ans1 = 0, ans2 = 0, ansWithout = 0;
        if ((zeroes + zero) <= maxZeroes && (ones + one) <= maxOnes) {
            ans1 = 1 + solve(i + 1, zeroes + zero, ones + one, strs, maxZeroes, maxOnes, dp);
            ans2 = solve(i + 1, zeroes, ones, strs, maxZeroes, maxOnes, dp);
        } else {
            ansWithout = solve(i + 1, zeroes, ones, strs, maxZeroes, maxOnes, dp);
        }
        return dp[i][zeroes][ones] = max({ans1, ans2, ansWithout});
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp (strs.size(), vector<vector<int>>(m + 1, vector <int>(n + 1, -1)));
        return solve(0, 0, 0, strs, m, n, dp);
    }
};

int main()
{
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}
