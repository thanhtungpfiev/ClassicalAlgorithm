/*
 * File: main.cpp
 * Project: PrintAnagramsTogether
 * File Created: Sunday, 12th June 2022 5:31:26 pm
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
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        // code here
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ht;
        for (auto e : string_list)
        {
            string order_word(e);
            sort(order_word.begin(), order_word.end());
            ht[order_word].push_back(e);
        }
        for (auto it : ht)
        {
            result.push_back(it.second);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> result = sl.Anagrams(words);
    for (const auto &r : result)
    {
        for (const auto &c : r)
        {
            cout << c << " ";
        }
    }
    cout << endl;
    words = {"no", "on", "is"};
    result = sl.Anagrams(words);
    for (const auto &r : result)
    {
        for (const auto &c : r)
        {
            cout << c << " ";
        }
    }
    cout << endl;
    return 0;
}