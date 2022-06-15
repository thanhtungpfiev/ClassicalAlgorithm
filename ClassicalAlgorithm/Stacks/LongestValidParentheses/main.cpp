/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 24 - 5 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st; // stores indexes
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = "(()";
    Solution sl;
    cout << sl.longestValidParentheses(s) << endl;
    s = ")()())";
    cout << sl.longestValidParentheses(s) << endl;
    return 0;
}
