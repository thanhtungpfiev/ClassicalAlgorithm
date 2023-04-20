/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 24 - 3 - 2022
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
#include <map>

using namespace std;

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

void bruteforce(const vector<string>& arr, const int& N)
{
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            string str1 = arr[i];
            string str2 = arr[j];
            if (str1.length() + str2.length() < 6 || (str1.length() == 3 && str2.length() == 3)) {
                continue;
            }
            if (str1.length() < str2.length()) {
                swap(str1, str2);
            }
            string temp1 = str1.size() > 4 ? str1.substr(str1.length() - 4) : str1;
            string temp2 = str2.size() > 4 ? str2.substr(str2.length() - 4) : str2;

            if (findSum(temp1 ,temp2) != "2021") {
                continue;
            }
            if (findSum(str1, str2).substr(0, 4) == "2020") {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

vector<long long> generatePossibleSum()
{
    vector<long long> possibleSum;
    possibleSum.push_back(202021);
    possibleSum.push_back(20202021);
    possibleSum.push_back(202002021);
    possibleSum.push_back(202012021);
    possibleSum.push_back(202022021);
    possibleSum.push_back(202032021);
    possibleSum.push_back(202042021);
    possibleSum.push_back(202052021);
    possibleSum.push_back(202062021);
    possibleSum.push_back(202072021);
    possibleSum.push_back(202082021);
    possibleSum.push_back(202092021);

    return possibleSum;
}

void greedy(map<long long, long long>& arr)
{
    long long cnt = 0;
    vector<long long> possibleSum = generatePossibleSum();
    for (auto const& [k, v] : arr) {
        for (int i = 0; i < possibleSum.size(); ++i) {
            int val  = possibleSum[i] - k;
            if (arr.find(val) != arr.end()) {
                cnt += v * arr[val];
            }
        }

    }
    cout << cnt / 2 << endl;
}

void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    while (T --> 0) {
        int N = 0;
        cin >> N;
//        vector<string> arr;
//        string temp;
//        for (int i = 0; i < N; ++i) {
//            cin >> temp;
//            arr.push_back(temp);
//        }
//        bruteforce(arr, N);
        map<long long, long long> arr;
        long long temp = 0;
        for (int i = 0; i < N; ++i) {
            cin >> temp;
            arr[temp] += 1;
        }
        greedy(arr);

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    inputByReadConsole();
    return 0;
}
