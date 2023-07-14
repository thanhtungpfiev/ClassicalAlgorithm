/*
 * File: main.cpp
 * Project: FindAndReplacePattern
 * File Created: Friday, 29th July 2022 10:47:30 am
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
    bool isIsomorphic(string &s, string &t)
    {
        unordered_map<char, char> ht;
        for (int i = 0; i < s.length(); ++i)
        {
            if (ht.find(s[i]) != ht.end())
            {
                if (ht[s[i]] != t[i])
                {
                    return false;
                }
            }
            else
            {
                for (auto it : ht)
                {
                    if (it.second == t[i])
                    {
                        return false;
                    }
                }
                ht[s[i]] = t[i];
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (auto word : words)
        {
            if (isIsomorphic(word, pattern))
            {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}