/*
 * File: main.cpp
 * Project: DecodeString
 * File Created: Monday, 15th August 2022 1:24:06 pm
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
    string decodeString(string s)
    {
        string result;
        stack<char> st;
        for (auto c : s)
        {
            if (c != ']')
            {
                st.push(c);
            }
            else
            {
                string temp;
                if (!st.empty())
                {
                    while (st.top() != '[')
                    {
                        temp += st.top();
                        st.pop();
                    }
                    st.pop();
                    int k = 1;
                    if (!st.empty())
                    {
                        string number;
                        while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                        {
                            number += st.top();
                            st.pop();
                        }
                        reverse(number.begin(), number.end());
                        k = stoi(number);
                    }
                    string temp1;
                    for (int i = 0; i < k; ++i)
                    {
                        temp1 += temp;
                    }
                    reverse(temp1.begin(), temp1.end());
                    for (auto e : temp1)
                    {
                        st.push(e);
                    }
                }
            }
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: s = "3[a]2[bc]"
    // Output: "aaabcbc"

    // Input: s = "3[a2[c]]"
    // Output: "accaccacc"

    // Input: s = "2[abc]3[cd]ef"
    // Output: "abcabccdcdcdef"

    return 0;
}