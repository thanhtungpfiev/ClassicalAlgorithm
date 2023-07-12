/*
 * File: main.cpp
 * Project: RearrangeCharactersToMakeTargetString
 * File Created: Monday, 6th June 2022 12:02:37 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        int cnt = s.length();
        map<char, int> ht1;
        map<char, int> ht2;

        for (int i = 0; i < s.length(); ++i)
        {
            if (target.find(s[i]) != string::npos)
            {
                ht1[s[i]]++;
            }
        }
        for (int i = 0; i < target.length(); ++i)
        {
            ht2[target[i]]++;
        }
        unordered_set<char> s1(target.begin(), target.end());
        for (const auto &e : s1)
        {
            if (ht1[e] / ht2[e] < cnt)
            {
                cnt = ht1[e] / ht2[e];
            }
        }
        return cnt;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "ilovecodingonleetcode", target = "code";
    cout << sl.rearrangeCharacters(s, target) << endl;
    s = "abcba", target = "abc";
    cout << sl.rearrangeCharacters(s, target) << endl;
    s = "abbaccaddaeea", target = "aaaaa";
    cout << sl.rearrangeCharacters(s, target) << endl;
    return 0;
}