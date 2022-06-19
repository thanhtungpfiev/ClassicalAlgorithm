/*
 * File: main.cpp
 * Project: LongestCommonSubsequence
 * File Created: Thursday, 16th June 2022 10:12:58 am
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
        string subsequence = "";
        int i = text1.length();
        int j = text2.length();
        while (dp[i][j] != 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                subsequence += text1[i - 1];
                --i;
                --j;
            }
            else
            {
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    --i;
                }
                else
                {
                    --j;
                }
            }
        }
        reverse(subsequence.begin(), subsequence.end());
        cout << subsequence << endl;
        return dp[text1.length()][text2.length()];
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string text1 = "abcde", text2 = "ace";
    cout << sl.longestCommonSubsequence(text1, text2) << endl;
    text1 = "abc", text2 = "abc";
    cout << sl.longestCommonSubsequence(text1, text2) << endl;
    text1 = "abc", text2 = "def";
    cout << sl.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}