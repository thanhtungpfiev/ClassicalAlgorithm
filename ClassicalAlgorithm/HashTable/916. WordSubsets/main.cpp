/*
 * File: main.cpp
 * Project: WordSubsets
 * File Created: Saturday, 30th July 2022 5:17:28 pm
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
    vector<int> count(string &s)
    {
        vector<int> freq(26);
        for (auto &c : s)
        {
            freq[c - 'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> maxFreq(26);
        vector<string> result;
        for (auto &word2 : words2)
        {
            vector<int> freq = count(word2);
            for (int i = 0; i < 26; ++i)
            {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        for (auto &word1 : words1)
        {
            vector<int> freq = count(word1);
            int i;
            for (i = 0; i < 26; ++i)
            {
                if (freq[i] < maxFreq[i])
                {
                    break;
                }
            }
            if (i == 26)
            {
                result.push_back(word1);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
    // Output: ["facebook","google","leetcode"]
    // Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
    // Output: ["apple","google","leetcode"]
    return 0;
}