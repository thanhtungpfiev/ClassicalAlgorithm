/*
 * File: main.cpp
 * Project: LongestRepeatingCharacterReplacement
 * File Created: Saturday, 13th August 2022 1:46:29 pm
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
    int characterReplacement(string s, int k)
    {
        int size = s.size();
        int result = 0;
        vector<int> count(26, 0);
        int start = 0, end = 0, globalMaxFreq = 0;
        for (; end < size; end++) {
            count[s[end] - 'A'] += 1;
            globalMaxFreq = max(globalMaxFreq, count[s[end] - 'A']);
            if ((end - start + 1) - globalMaxFreq > k) {
                result = max(result, end - start);
                count[s[start] - 'A']--;
                start += 1;
            }
        }
        return max(result, end - start);
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}