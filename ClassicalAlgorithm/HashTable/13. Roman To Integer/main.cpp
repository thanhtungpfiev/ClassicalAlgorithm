/*
 * File: main.cpp
 * Project: RomanToInteger
 * File Created: Monday, 15th August 2022 1:43:52 pm
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
    int romanToInt(string s)
    {
        int result = 0;
        unordered_map<char, int> ht;
        ht['I'] = 1;
        ht['V'] = 5;
        ht['X'] = 10;
        ht['L'] = 50;
        ht['C'] = 100;
        ht['D'] = 500;
        ht['M'] = 1000;

        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (i != s.length() - 1)
            {
                if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) || (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) || (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))
                {
                    result -= ht[s[i]];
                }
                else
                {
                    result += ht[s[i]];
                }
            }
            else
            {
                result += ht[s[i]];
            }
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: s = "III"
    // Output: 3
    // Explanation: III = 3.

    // Input: s = "LVIII"
    // Output: 58
    // Explanation: L = 50, V= 5, III = 3.

    // Input: s = "MCMXCIV"
    // Output: 1994
    // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    return 0;
}