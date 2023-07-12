/*
 * File: main.cpp
 * Project: BullsAndCows
 * File Created: Sunday, 14th August 2022 12:09:39 pm
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
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        int cows = 0;
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        for (int i = 0; i < secret.length(); ++i)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i)
        {
            cows += min(s[i], g[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: secret = "1807", guess = "7810"
    // Output: "1A3B"
    // Explanation: Bulls are connected with a '|' and cows are underlined:
    // "1807"
    // |
    // "7810"

    // Input: secret = "1123", guess = "0111"
    // Output: "1A1B"
    // Explanation: Bulls are connected with a '|' and cows are underlined:
    // "1123"        "1123"
    // |      or     |
    // "0111"        "0111"
    // Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

    // 1 <= secret.length, guess.length <= 1000
    // secret.length == guess.length
    // secret and guess consist of digits only.
    return 0;
}