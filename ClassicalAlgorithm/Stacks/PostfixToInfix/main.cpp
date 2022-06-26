/*
 * File: main.cpp
 * Project: PostfixToInfix
 * File Created: Saturday, 25th June 2022 2:35:55 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    string postfixToInfix(const string &str)
    {
        stack<string> st;
        for (const auto &c : str)
        {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                st.push(string("(" + operand2 + c + operand1 + ")"));
            }
        }
        return st.top();
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "abc++";
    cout << sl.postfixToInfix(s) << endl;
    s = "ab*c+";
    cout << sl.postfixToInfix(s) << endl;
    return 0;
}