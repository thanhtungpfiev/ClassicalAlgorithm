/*
 * File: main.cpp
 * Project: FindAllAnagramsInAString
 * File Created: Saturday, 13th August 2022 11:29:05 am
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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        int N = s.length();
        int M = p.length();
        if (M > N)
        {
            return result;
        }
        vector<int> freq_p(26, 0);
        vector<int> freq_s(26, 0);
        for (int i = 0; i < M; ++i)
        {
            freq_p[p[i] - 'a']++;
            freq_s[s[i] - 'a']++;
        }
        if (freq_s == freq_p)
        {
            result.push_back(0);
        }
        for (int i = M; i < N; ++i)
        {
            freq_s[s[i] - 'a']++;
            freq_s[s[i - M] - 'a']--;
            if (freq_s == freq_p)
            {
                result.push_back(i - M + 1);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: s = "cbaebabacd", p = "abc"
    // Output: [0,6]
    // Explanation:
    // The substring with start index = 0 is "cba", which is an anagram of "abc".
    // The substring with start index = 6 is "bac", which is an anagram of "abc".

    // Input: s = "abab", p = "ab"
    // Output: [0,1,2]
    // Explanation:
    // The substring with start index = 0 is "ab", which is an anagram of "ab".
    // The substring with start index = 1 is "ba", which is an anagram of "ab".
    // The substring with start index = 2 is "ab", which is an anagram of "ab".
    return 0;
}