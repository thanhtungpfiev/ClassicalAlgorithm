/*
 * File: main.cpp
 * Project: 17. Letter Combinations of a Phone Number
 * File Created: Wednesday, 2nd August 2023 2:41:20 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}

class Solution
{
public:
    void generate(vector<string> &result, string &candidate, string &digits, map<char, vector<char>> &m, int step)
    {
        if (step == digits.length())
        {
            result.push_back(candidate);
            return;
        }
        char c = digits[step];
        vector<char> v = m[c];
        for (int i = 0; i < v.size(); ++i)
        {
            candidate.push_back(v[i]);
            generate(result, candidate, digits, m, step + 1);
            candidate.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        map<char, vector<char>> m =
            {
                {'2', vector<char>{'a', 'b', 'c'}},
                {'3', vector<char>{'d', 'e', 'f'}},
                {'4', vector<char>{'g', 'h', 'i'}},
                {'5', vector<char>{'j', 'k', 'l'}},
                {'6', vector<char>{'m', 'n', 'o'}},
                {'7', vector<char>{'p', 'q', 'r', 's'}},
                {'8', vector<char>{'t', 'u', 'v'}},
                {'9', vector<char>{'w', 'x', 'y', 'z'}},
            };
        if (!digits.empty())
        {
            string candidate;
            generate(result, candidate, digits, m, 0);
        }
        return result;
    }
};