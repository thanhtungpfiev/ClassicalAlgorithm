/*
 * File: main.cpp
 * Project: BackspaceStringCompare
 * File Created: Monday, 15th August 2022 11:19:49 am
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
    stack<char> buildString(string &str)
    {
        stack<char> st;
        for (auto c : str)
        {
            if (c != '#')
            {
                st.push(c);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }
        return st;
    }
    bool backspaceCompare(string s, string t)
    {
        return buildString(s) == buildString(t);
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: s = "ab#c", t = "ad#c"
    // Output: true
    // Explanation: Both s and t become "ac".

    // Input: s = "ab##", t = "c#d#"
    // Output: true
    // Explanation: Both s and t become "".

    // Input: s = "a#c", t = "b"
    // Output: false
    // Explanation: s becomes "c" while t becomes "b".

    return 0;
}