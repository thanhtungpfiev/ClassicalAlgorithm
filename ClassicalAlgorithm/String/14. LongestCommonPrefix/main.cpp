/*
 * File: main.cpp
 * Project: LongestCommonPrefix
 * File Created: Thursday, 18th August 2022 11:46:34 am
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
    string longestCommonPrefixUtil(const string &s1, const string &s2)
    {
        string result;
        int len = min(s1.length(), s2.length());
        for (int i = 0; i < len; ++i)
        {
            if (s1[i] != s2[i])
                break;
            result += s1[i];
        }
        return result;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = strs[0];
        for (auto str : strs)
        {
            result = longestCommonPrefixUtil(result, str);
            if (result.empty())
            {
                return result;
            }
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: strs = ["flower","flow","flight"]
    // Output: "fl"

    // Input: strs = ["dog","racecar","car"]
    // Output: ""
    // Explanation: There is no common prefix among the input strings.
    return 0;
}