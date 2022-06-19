/*
 * File: main.cpp
 * Project: GreatestEnglishLetterInUpperAndLowerCase
 * File Created: Sunday, 19th June 2022 12:58:38 pm
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
    string greatestLetter(string s)
    {
        string result;
        for (char c = 'a'; c >= 'a' && c <= 'z'; c++)
        {
            if (s.find(c) != string::npos && s.find(toupper(c)) != string::npos)
            {
                result = toupper(c);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "lEeTcOdE";
    cout << sl.greatestLetter(s) <<endl;
    s = "arRAzFif";
    cout << sl.greatestLetter(s) <<endl;
    s = "AbCdEfGhIjK";
    cout << sl.greatestLetter(s) <<endl;
    return 0;
}