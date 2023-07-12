/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/31/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        unordered_set<string> os;
        for (int i = 0; i <= s.size() - k; ++i) {
            string e = s.substr(i, k);
            os.insert(e);
        }
        return os.size() == pow(2, k);
    }
};

int main()
{
    string s = "00110110";
    int k = 2;
    Solution sl;
    cout << sl.hasAllCodes(s, k) << endl;
    s = "0110";
    k = 1;
    cout << sl.hasAllCodes(s, k) << endl;
    s = "0110";
    k = 2;
    cout << sl.hasAllCodes(s, k) << endl;
    return 0;
}
