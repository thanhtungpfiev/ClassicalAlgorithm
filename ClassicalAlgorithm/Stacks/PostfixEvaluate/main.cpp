#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        int result = 0;
        for (auto c : S)
        {
            if (c >= '0' && c <= '9')
            {
                st.push(c - '0');
            }
            else
            {

                int secondOperand = st.top();
                st.pop();
                int firstOperand = st.top();
                st.pop();
                switch (c)
                {
                case '+':
                    result = firstOperand + secondOperand;
                    break;
                case '-':
                    result = firstOperand - secondOperand;
                    break;
                case '*':
                    result = firstOperand * secondOperand;
                    break;
                case '/':
                    result = firstOperand / secondOperand;
                    break;
                default:
                    break;
                }
                st.push(result);
            }
        }
        if (!st.empty())
        {
            result = st.top();
            st.pop();
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string S = "231*+9-";
    cout << sl.evaluatePostfix(S) << endl;
    return 0;
}