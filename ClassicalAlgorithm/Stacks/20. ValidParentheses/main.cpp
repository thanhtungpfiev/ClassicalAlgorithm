/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 25 - 5 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    string s = "]";
    Solution sl;
    cout << sl.isValid(s) << endl;
    s = "()";
    cout << sl.isValid(s) << endl;
    s = "()[]{}";
    cout << sl.isValid(s) << endl;
    s = "(]";
    cout << sl.isValid(s) << endl;
    return 0;
}
