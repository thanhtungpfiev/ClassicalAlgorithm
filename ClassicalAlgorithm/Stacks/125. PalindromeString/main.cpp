#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string test;
        for (auto c : s)
        {
            c = tolower(c);
            if (isalnum(c))
            {
                test += c;
            }
        }
        if (test.length() < 2)
        {
            return true;
        }
        stack<char> st;
        int mid = test.length() / 2;
        for (int i = 0; i < mid; ++i)
        {
            st.push(test[i]);
        }
        if (test.length() % 2)
        {
            ++mid;
        }
        for (int i = mid; i < test.length(); ++i)
        {
            if (st.top() != test[i])
            {
                return false;
            }
            st.pop();
        }

        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string s = "A man, a plan, a canal: Panama";
    cout << sl.isPalindrome(s) << endl;
    s = "race a car";
    cout << sl.isPalindrome(s) << endl;
    s = " ";
    cout << sl.isPalindrome(s) << endl;
    return 0;
}