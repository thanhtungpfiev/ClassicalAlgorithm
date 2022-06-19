/*
 * File: main.cpp
 * Project: LongestBinarySubsequenceLessThanOrEqualToK
 * File Created: Sunday, 19th June 2022 2:07:54 pm
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
    int longestSubsequence(string s, int k)
    {
        int cnt = 0, val = 0, pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i)
        {
            if (s[i] == '1')
            {
                cnt++;
                val += pow;
            }
            pow <<= 1;
        }
        return count(s.begin(), s.end(), '0') + cnt;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "1001010";
    int k = 5;
    cout << sl.longestSubsequence(s, k) << endl;
    s = "00101001", k = 1;
    cout << sl.longestSubsequence(s, k) << endl;
    return 0;
}