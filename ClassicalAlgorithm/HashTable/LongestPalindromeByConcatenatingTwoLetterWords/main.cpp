/*
 * File: main.cpp
 * Project: LongestPalindromeByConcatenatingTwoLetterWords
 * File Created: Monday, 22nd August 2022 9:04:49 pm
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
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> ht;
        int unpaired = 0, result = 0;
        for (auto word : words)
        {
            if (word[0] == word[1])
            {
                if (ht[word] > 0)
                {
                    ht[word]--;
                    unpaired--;
                    result += 4;
                }
                else
                {
                    ht[word]++;
                    unpaired++;
                }
            }
            else
            {
                string rev = word;
                reverse(rev.begin(), rev.end());
                if (ht[rev] > 0)
                {
                    ht[rev]--;
                    result += 4;
                }
                else
                {
                    ht[word]++;
                }
            }
        }
        if (unpaired)
        {
            result += 2;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: words = ["lc","cl","gg"]
    // Output: 6
    // Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
    // Note that "clgglc" is another longest palindrome that can be created.

    // Input: words = ["ab","ty","yt","lc","cl","ab"]
    // Output: 8
    // Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
    // Note that "lcyttycl" is another longest palindrome that can be created.

    // Input: words = ["cc","ll","xx"]
    // Output: 2
    // Explanation: One longest palindrome is "cc", of length 2.
    // Note that "ll" is another longest palindrome that can be created, and so is "xx".
    return 0;
}