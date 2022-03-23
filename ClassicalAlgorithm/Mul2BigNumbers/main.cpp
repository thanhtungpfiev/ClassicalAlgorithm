/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/23/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int convertCharToNumber(char c)
{
    int number;
    if (c >= '0' && c <= '9') {
        number = int(c) - '0';
    } else {
        number = int(c) - 'A' + 10;
    }
    return number;
}

char convertNumberToChar(int num)
{
    char ch;
    if (num >= 0 && num <= 9) {
        ch = char(num + '0');
    } else {
        ch = char(num - 10 + 'A');
    }
    return ch;
}

string mul(string& S, string &D, int B)
{
    string result;
    vector<int> temp(S.size() + D.size() - 1);

    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < D.size(); ++j) {
            temp[i + j] += (convertCharToNumber(S[i]) * convertCharToNumber(D[j]));
        }
    }
    for (int i = temp.size() - 1; i > 0; --i) {
        if (temp[i] >= B) {
            temp[i - 1] +=  temp[i] / B;
            temp[i] %= B;
        }
    }
    if (temp[0] >= B) {
        int new0 = temp[0] / B;
        temp[0] %= B;
        temp.insert(temp.begin(), new0);
    }
    for (int i = 0; i < temp.size(); ++i) {
        result += convertNumberToChar(temp[i]);
    }
    return result;
}

int main()
{
    string S = "999999999";
    string D = "999999999";
    cout << mul(S, D, 10) << endl;
    return 0;
}
