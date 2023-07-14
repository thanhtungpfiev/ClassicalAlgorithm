/*
 * File: main.cpp
 * Project: PrefixToInfix
 * File Created: Saturday, 25th June 2022 2:46:14 pm
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
    string prefixToInfix(const string &str)
    {
        stack<string> st;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            if (isalnum(str[i]))
            {
                st.push(string(1, str[i]));
            }
            else
            {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                st.push(string("(" + operand1 + str[i] + operand2 + ")"));
            }
        }
        return st.top();
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "*+AB-CD";
    cout << sl.prefixToInfix(s) << endl;
    s = "*-A/BC-/AKL";
    cout << sl.prefixToInfix(s) << endl;
    return 0;
}