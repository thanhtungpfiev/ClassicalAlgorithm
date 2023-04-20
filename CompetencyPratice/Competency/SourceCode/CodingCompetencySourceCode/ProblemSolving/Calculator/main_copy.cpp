/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/13/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <algorithm>

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

long long convertBaseToDec(string& str, int base)
{
    long long result = 0;
    int power = 1;
    for (int i = str.size() - 1; i >= 0; --i) {
        result += convertCharToNumber(str[i]) * power;
        power = power * base;
    }
    return result;
}

string convertDecToBase(long long num, int base)
{
    string result;
    while (num > 0) {
        result.push_back(convertNumberToChar(num % base));
        num /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int N = 5;
    cin >> N;
    while (N --> 0) {
        int B = 10;
        cin >> B;
        string S = "-3214";
        cin >> S;
        string D = "-987";
        cin >> D;
        if (S == "0" || D == "0") {
            cout << 0 << endl;
        } else {
            bool isSNegative = false;
            bool isDNegative = false;
            if  (S[0] == '-') {
                S = S.substr(1, S.size() - 1);
                isSNegative = true;
            }
            if  (D[0] == '-') {
                D = D.substr(1, D.size() - 1);
                isDNegative = true;
            }
            long long mul = convertBaseToDec(S, B) * convertBaseToDec(D, B);
            string result = convertDecToBase(mul, B);
            if (isSNegative != isDNegative) {
                result.insert(result.begin(), '-');
            }
            cout << result << endl;
        }

    }
    return 0;
}
