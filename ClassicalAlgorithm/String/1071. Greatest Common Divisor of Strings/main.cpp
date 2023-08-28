/*
 * File: main.cpp
 * Project: 1071. Greatest Common Divisor of Strings
 * File Created: Thursday, 24th August 2023 1:55:31 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length()) {
            return gcdOfStrings(str2, str1);
        } else if (str1.find(str2) != 0) {
            return "";
        } else if (str2 == "") {
            return str1;
        } else {
            return gcdOfStrings(str1.substr(str2.length()), str2);
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string str1 = "ABABAB", str2 = "ABAB";
    cout << sl.gcdOfStrings(str1, str2) << endl;
    return 0;
}