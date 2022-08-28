/*
 * File: main.cpp
 * Project: RansomNote
 * File Created: Thursday, 25th August 2022 10:07:15 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> count_magazine(26, 0);
        for (auto c : magazine)
        {
            count_magazine[c - 'a']++;
        }
        for (auto c : ransomNote)
        {
            if (count_magazine[c - 'a'] <= 0)
                return false;
            count_magazine[c - 'a']--;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: ransomNote = "a", magazine = "b"
    // Output: false

    // Input: ransomNote = "aa", magazine = "ab"
    // Output: false

    // Input: ransomNote = "aa", magazine = "aab"
    // Output: true
    return 0;
}