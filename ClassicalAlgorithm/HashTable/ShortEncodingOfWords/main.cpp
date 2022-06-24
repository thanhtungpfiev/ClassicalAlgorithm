/*
 * File: main.cpp
 * Project: ShortEncodingOfWords
 * File Created: Monday, 20th June 2022 1:21:24 pm
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
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> ht(words.begin(), words.end());
        for (auto &s : ht)
        {
            for (int i = 1; i <= s.length(); ++i)
            {
                ht.erase(s.substr(i));
            }
        }
        int ans = 0;
        for (auto &s : ht)
        {
            ans += s.length() + 1;
        }
        return ans;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<string> words = {"time", "me", "bell"};
    cout << sl.minimumLengthEncoding(words) << endl;
    words = {"t"};
    cout << sl.minimumLengthEncoding(words) << endl;
    return 0;
}