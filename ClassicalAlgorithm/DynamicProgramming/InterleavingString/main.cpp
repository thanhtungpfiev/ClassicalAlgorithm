/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/19/2021
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
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> table(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        for (int i = 0; i < s1.length() + 1; ++i) {
            for (int j = 0; j < s2.length() + 1; ++j) {
                if (i == 0 && j == 0) {
                    table[0][0] = true;
                } else if (i == 0) {
                    table[i][j] = table[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    table[i][j] = table[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return table[s1.length()][s2.length()];
    }
};

class Solution1 {
public:
    bool isInterleave(string &s1, int i, string &s2, int j, string &s3, int k, vector<vector<int>> &dp) {
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool ans = false;
        if ((s1[i] == s3[k] && isInterleave(s1, i + 1, s2, j, s3, k + 1, dp))
            || (s2[j] == s3[k] && isInterleave(s1, i, s2, j + 1, s3, k + 1, dp))) {
            ans = true;
        }
        dp[i][j] = ans ? 1 : 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return isInterleave(s1, 0, s2, 0, s3, 0, dp);
    }
};

int main()
{
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool result = s.isInterleave(s1, s2, s3);
    cout << result << endl;
    return 0;
}
