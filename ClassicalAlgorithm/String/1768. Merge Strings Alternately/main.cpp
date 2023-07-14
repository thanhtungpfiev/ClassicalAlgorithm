/*
 * File: main.cpp
 * Project: 1768. Merge Strings Alternately
 * File Created: Friday, 14th July 2023 11:57:26 am
 * Author: DTA3HC (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";
        int length = word1.length();
        if (word1.length() > word2.length())
        {
            length = word2.length();
        }
        for (int i = 0; i < length; ++i)
        {
            result += word1[i];
            result += word2[i];
        }

        result += word1.substr(length) + word2.substr(length);

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    return 0;
}