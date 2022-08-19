/*
 * File: main.cpp
 * Project: FirstUniqueCharacterInAString
 * File Created: Tuesday, 16th August 2022 11:00:59 am
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
    typedef pair<int, int> mPair;
    struct CompareFreq
    {
        bool operator()(const mPair &p1, const mPair &p2)
        {
            if (p1.second == p2.second)
            {
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        }
    };
    int firstUniqChar(string s)
    {
        unordered_map<char, mPair> freq;
        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i]].first = i;
            freq[s[i]].second++;
        }
        priority_queue<mPair, vector<mPair>, CompareFreq> pq;
        for (auto it : freq)
        {
            pq.push(make_pair(it.second.first, it.second.second));
        }
        if (pq.top().second == 1)
        {
            return pq.top().first;
        }
        return -1;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);
        for (auto c : s)
        {
            freq[c - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (freq[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: s = "leetcode"
    // Output: 0

    // Input: s = "loveleetcode"
    // Output: 2

    // Input: s = "aabb"
    // Output: -1
    return 0;
}