/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 22 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

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

string mul(vector<int>& S, vector<int>& D, int B)
{
    string result;
    vector<int> temp(S.size() + D.size() - 1);

    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < D.size(); ++j) {
            temp[i + j] += ((S[i]) * (D[j]));
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

void genBinaryArrayAndFindBest(const vector<int>& arr, vector<int>& c, long long& best, int step)
{
    if (step == c.size()) {
        int cnt1 = 0, cnt2 = 0;
        long long firstNumber = 0, secondNumber = 0;
        for (int i = c.size() - 1; i >= 0; --i) {
            if (c[i] == false) {
                firstNumber += arr[i] * pow(10, cnt1);
                ++cnt1;
            } else {
                secondNumber += arr[i] * pow(10, cnt2);
                ++cnt2;
            }
        }
        best = max(best, firstNumber * secondNumber);
        return;
    }
    for (int i = 0; i < 2; ++i) {
        c[step] = i;
        genBinaryArrayAndFindBest(arr, c, best, step + 1);
    }
}

long long greedy(const vector<int>& arr)
{
    long long result = 0, firstNumber = 0, secondNumber = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (firstNumber < secondNumber) {
            firstNumber = firstNumber * 10 + arr[i];
        } else {
            secondNumber = secondNumber * 10 + arr[i];
        }
    }
    result = firstNumber * secondNumber;
    return result;
}

void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    string s = "";
    while (T --> 0) {
        cin >> s;
        vector<int> arr;
        vector<int> S;
        vector<int> D;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '6') {
                arr.push_back(9);
            } else {
                arr.push_back(convertCharToNumber(s[i]));
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long long result = 0;
//        vector<int> c(arr.size());
//        genBinaryArrayAndFindBest(arr, c, result, 0);
        result = greedy(arr);
        cout << result << endl;
    }
}

void inputByReadFile()
{
    ifstream fileInput("/media/sf_D_DRIVE/CodingPractices/LGECodeJamCoding/LGECodeJamCoding/2021OnlineRound1/NumberCardGame/input.txt");
    string str;
    fileInput >> str;
    int T = 0;
    fileInput >> T;
    string s = "";
    while (T --> 0) {
        fileInput >> s;
        vector<int> arr;
        vector<int> S;
        vector<int> D;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '6') {
                arr.push_back(9);
            } else {
                arr.push_back(convertCharToNumber(s[i]));
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        long long result = 0;
//        vector<int> c(arr.size());
//        genBinaryArrayAndFindBest(arr, c, result, 0);
        result = greedy(arr);
        cout << result << endl;
    }
}

int main()
{
    inputByReadConsole();
    return 0;
}
