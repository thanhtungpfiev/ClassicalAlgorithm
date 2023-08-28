/*
 * File: main.cpp
 * Project: IsSubsequence
 * File Created: Tuesday, 19th July 2022 2:07:26 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.length() > t.length())
        {
            return false;
        }
        if (longestCommonSubsequence(s, t) != s.length())
        {
            return false;
        }
        return true;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp = vector<vector<int>>(text1.length() + 1, vector<int>(text2.length() + 1));
        for (int i = 1; i <= text1.length(); ++i)
        {
            for (int j = 1; j <= text2.length(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[texta1.length()][text2.length()];
    }
};

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        unordered_map<char, vector<int>> ht;
        for (int i = 0; i < t.length(); ++i)
        {
            ht[t[i]].push_back(i);
        }
        int prev = -1;
        for (auto c : s)
        {
            auto &v = ht[c];
            auto it = upper_bound(v.begin(), v.end(), prev);
            if (it == v.end())
            {
                return false;
            }
            else
            {
                prev = *it;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) {
            return false;
        }
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            bool isFound = false;
            for (int j = start; j < t.length(); ++j) {
                if (t[j] == s[i]) {
                    isFound = true;
                    start = j + 1;
                    break;
                }
            }
            if (isFound == false) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: s = "abc", t = "ahbgdc"
    // Output: true
    // Input: s = "axc", t = "ahbgdc"
    // Output: false
    return 0;
}