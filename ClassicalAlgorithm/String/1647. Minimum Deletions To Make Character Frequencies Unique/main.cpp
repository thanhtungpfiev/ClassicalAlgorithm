/*
 * File: main.cpp
 * Project: MinimumDeletionsToMakeCharacterFrequenciesUnique
 * File Created: Tuesday, 28th June 2022 11:43:30 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        int result = 0;
        vector<int> frequences(26);
        for (auto c : s)
        {
            frequences[c - 'a']++;
        }
        unordered_set<int> ht2;
        for (auto &e : frequences)
        {
            while (e > 0 && ht2.find(e) != ht2.end())
            {
                --e;
                ++result;
            }
            if (e > 0)
            {
                ht2.insert(e);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "aab";
    cout << sl.minDeletions(s) << endl;
    s = "aaabbbcc";
    cout << sl.minDeletions(s) << endl;
    s = "ceabaacb";
    cout << sl.minDeletions(s) << endl;
    return 0;
}