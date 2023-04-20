/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/2/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>

using namespace std;

bool isPalindrome(string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

string exhaustiveCheck(string s) { // search all config
    string result;
    int max = 0;
    int imax = 0;
    int jmax = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if (isPalindrome(s, i, j) && (j - i + 1) > max) {
                max = j - i + 1;
                imax = i;
                jmax = j;
            }
        }
    }
    result = s.substr(imax, max);
    cout << result << " " << max << endl;
    return result;
}

string exhaustiveCheck2(string s) { // just check configs which have length > max
    string result;
    int max = 0;
    int imax = 0;
    int jmax = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if ((j - i + 1) > max && isPalindrome(s, i, j)) {
                max = j - i + 1;
                imax = i;
                jmax = j;
            }
        }
    }
    result = s.substr(imax, max);
    cout << result << " " << max << endl;
    return result;
}

string exhaustiveCheck3(string s) { // search from longest string
    string result;
    int max = 0;
    int imax = 0;
    int jmax = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = s.length() - 1; j >=i; --j) {
            if ((j - i + 1) > max && isPalindrome(s, i, j)) {
                max = j - i + 1;
                imax = i;
                jmax = j;
            }
        }
    }
    result = s.substr(imax, max);
    cout << result << " " << max << endl;
    return result;
}

string dp(string s) {
    string result;
    int n = s.size();
    if (n == 0) {
        return result;
    }
    bool dp[n][n] = {false};
    for (int i = 0; i < n; ++i) { // base case with 1 and 2 letter
        dp[i][i] = true;
        if (i == n - 1) break;
        dp[i][i + 1] = (s[i] == s[i + 1]);
    }
    for (int i = n - 3; i >= 0; --i) { // dp for >= 3 letter
        for (int j = i + 2; j < n; ++j) {
            dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        }
    }
    int max = 0;
    int imax = 0;
    int jmax = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if ((j - i + 1) > max && dp[i][j]) {
                max = j - i + 1;
                imax = i;
                jmax = j;
            }
        }
    }
    result = s.substr(imax, max);
    cout << result << " " << max << endl;
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    dp("babad");
    dp("cbbd");
    dp("a");
    dp("ac");
    return 0;
}
