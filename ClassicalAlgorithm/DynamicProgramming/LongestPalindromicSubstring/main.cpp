/*
 * File: main.cpp
 * Project: LongestPalindromicSubstring
 * File Created: Thursday, 16th June 2022 8:02:55 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result;
        int n = s.size();
        if (n == 0)
        {
            return result;
        }
        bool dp[1000][1000] = {false};
        for (int i = 0; i < n; ++i)
        { // base case with 1 and 2 letter
            dp[i][i] = true;
            if (i == n - 1)
                break;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int i = n - 3; i >= 0; --i)
        { // dp for >= 3 letter
            for (int j = i + 2; j < n; ++j)
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        int max = 0;
        int imax = 0;
        int jmax = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j < s.length(); ++j)
            {
                if ((j - i + 1) > max && dp[i][j])
                {
                    max = j - i + 1;
                    imax = i;
                    jmax = j;
                }
            }
        }
        result = s.substr(imax, max);
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "babad";
    cout << sl.longestPalindrome(s) << endl;
    s = "cbbd";
    cout << sl.longestPalindrome(s) << endl;
    return 0;
}