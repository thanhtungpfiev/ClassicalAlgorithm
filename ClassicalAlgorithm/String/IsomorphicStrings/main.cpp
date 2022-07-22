/*
 * File: main.cpp
 * Project: IsomorphicStrings
 * File Created: Tuesday, 19th July 2022 11:51:37 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
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
    bool isIsomorphic(string s, string t)
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
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: s = "egg", t = "add"
    // Output: true
    // Input: s = "foo", t = "bar"
    // Output: false
    // Input: s = "paper", t = "title"
    // Output: true
    unordered_map<int, int> ht;
    cout << ht[1] << endl;
    return 0;
}