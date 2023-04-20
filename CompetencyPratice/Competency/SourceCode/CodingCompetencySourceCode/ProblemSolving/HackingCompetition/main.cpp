/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/14/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string simulator(string& S, string& C)
{
    int n = S.length();
    int cursor = n;

    for (int i = 0; i < C.length(); ++i) {
        if (C[i] == 'L') {
            if (cursor != 0) {
                cursor--;
            }
        } else if (C[i] == 'R') {
            if (cursor != n) {
                cursor++;
            }
        } else  if (C[i] == 'B') {
            if (cursor == 0) {
                continue;
            }
            string tmp = "";
            for (int j = 0; j < n; ++j) {
                if (j != cursor - 1) {
                    tmp += S[j];
                }
            }
            --cursor;
            --n;
            S = tmp;
        } else {
            string tmp = "";
            for (int j = 0; j < cursor; ++j) {
                tmp += S[j];
            }
            tmp += C[i];
            for (int j = cursor; j < n; ++j) {
                tmp += S[j];
            }
            ++cursor;
            ++n;
            S = tmp;
        }
    }
    return S;
}

string using_stack(string& S, string& C)
{
    stack<char> s1, s2;
    for (auto c : S) {
        s1.push(c);
    }
    for (auto c : C) {
        if (c == 'L') {
            if (s1.empty()) {
                continue;
            }
            char x = s1.top();
            s1.pop();
            s2.push(x);
        } else if (c == 'R') {
            if (s2.empty()) {
                continue;
            }
            char x = s2.top();
            s2.pop();
            s1.push(x);
        } else if (c == 'B') {
            if (s1.empty()) {
                continue;
            }
            s1.pop();
        } else {
            s1.push(c);
        }

    }
    string result = "";
    while (!s1.empty()) {
        result += s1.top();
        s1.pop();
    }
    reverse(result.begin(), result.end());
    while (!s2.empty()) {
        result += s2.top();
        s2.pop();
    }
    return result;
}

int main()
{
    string S = "", C = "";
    cin >> S >> C;
    S = using_stack(S, C);
    cout << S << endl;
    return 0;
}
