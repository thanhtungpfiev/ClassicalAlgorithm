/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/26/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 ***********************************************************************/
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    // Function to return precedence of operators
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string result = "";
        string op = "+-*/^()";
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (op.find(s[i]) == std::string::npos)
            {
                result += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    if (s[i] == '^' && st.top() == '^')
                        break;
                    else
                    {
                        result += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    Solution sl;
    cout << sl.infixToPostfix(str) << endl;
    return 0;
}
