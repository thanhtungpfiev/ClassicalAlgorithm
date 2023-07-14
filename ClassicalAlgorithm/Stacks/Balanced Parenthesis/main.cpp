/*
 * File: main.cpp
 * Project: BalancedParenthesis
 * File Created: Thursday, 23rd June 2022 4:37:32 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <stack>

using namespace std;

bool valid(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        switch (c)
        {
        case '(':
        case '{':
        case '[':
            st.push(c);
            break;
        case ')':
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
            }
            break;
        case '}':
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
            }
            break;
        case ']':
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
            }
            break;
        }
    }
    return st.empty();
}

int main(int argc, char **argv)
{
    string S = "()[]{}";
    cout << valid(S) << endl;
    S = "())({}";
    cout << valid(S) << endl;
    return 0;
}