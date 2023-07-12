/*
 * File: main.cpp
 * Project: SubstringWithConcatenationOfAllWords
 * File Created: Saturday, 13th August 2022 6:34:32 pm
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
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.length();
        int k = words.size();
        int wordLength = words[0].length();
        int substringSize = k * wordLength;
        vector<int> result;
        unordered_map<string, int> ht;
        for (auto word : words)
        {
            ht[word]++;
        }
        for (int i = 0; i < n - substringSize + 1; ++i)
        {
            if (check(i, k, substringSize, wordLength, s, ht))
            {
                result.push_back(i);
            }
        }
        return result;
    }

    bool check(int i, int k, int substringSize, int wordLength, string &s, unordered_map<string, int> ht)
    {
        int wordUsed = 0;
        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength)
        {
            string sub = s.substr(j, wordLength);
            if (ht.find(sub) != ht.end() && ht[sub] != 0)
            {
                ht[sub]--;
                wordUsed++;
            }
            else
            {
                break;
            }
        }
        return wordUsed == k;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}