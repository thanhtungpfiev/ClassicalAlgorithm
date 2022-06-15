/*
 * File: main.cpp
 * Project: LongestStringChain
 * File Created: Wednesday, 15th June 2022 2:58:45 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &first, const string &second)
             { return first.length() < second.length(); });
        unordered_map<string, int> dp;
        int res = 0;
        for (auto &word : words)
        {
            dp[word] = 1;
            for (int i = 0; i < word.length(); ++i)
            {
                string newWord = word;
                newWord.erase(i, 1);
                if (dp.find(newWord) != dp.end() && dp[newWord] + 1 > dp[word])
                {
                    dp[word] = dp[newWord] + 1;
                }
            }
            res = max(res, dp[word]);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << sl.longestStrChain(words) << endl;
    words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << sl.longestStrChain(words) << endl;
    return 0;
}