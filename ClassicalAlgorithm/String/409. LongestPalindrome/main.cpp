/*
 * File: main.cpp
 * Project: LongestPalindrome
 * File Created: Friday, 22nd July 2022 10:57:27 am
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
    int longestPalindrome(string s)
    {
        int result = 0;
        unordered_map<char, int> ht;
        for (auto c : s)
        {
            ht[c]++;
        }
        for (auto it : ht)
        {
            result += it.second / 2 * 2;
            if (result % 2 == 0 && it.second % 2 == 1)
            {
                result++;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: s = "abccccdd"
    // Output: 7
    // Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
    // Input: s = "a"
    // Output: 1
    // Explanation: The longest palindrome that can be built is "a", whose length is 1.
    return 0;
}