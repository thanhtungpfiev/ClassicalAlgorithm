/*
 * File: main.cpp
 * Project: 1456. Maximum Number of Vowels in a Substring of Given Length
 * File Created: Monday, 28th August 2023 11:08:04 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int result = 0;
        string vowels = "aeiou";
        int temp = 0;
        for (int i = 0; i < k; ++i) {
            if (vowels.find(s[i]) != string::npos) {
                temp++;
            }
        }
        result = temp;
        cout << result << endl;
        for (int i = 1; i <= s.length() - k; ++i) {
            if (vowels.find(s[i - 1]) != string::npos && temp > 0) {
                temp--;
            }
            if (vowels.find(s[i + k - 1]) != string::npos) {
                temp++;
            }
            if (temp > result) {
                result = temp;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "tnfazcwrryitgacaabwm";
    int k = 4;
    cout << sl.maxVowels(s, k) << endl;
    return 0;
}