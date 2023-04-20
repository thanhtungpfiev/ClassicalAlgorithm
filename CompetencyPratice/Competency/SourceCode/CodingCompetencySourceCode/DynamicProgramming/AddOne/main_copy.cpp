/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/20/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;
const int mod = 1000000007;

int convertCharToNum(char c)
{
    int temp = int(c) - '0';
    return temp;
}

int calculate(vector<int>& nums, int m)
{
    vector<int> digits;
    int result;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == 9) {
                digits.push_back(1);
                digits.push_back(0);
            } else {
                digits.push_back(nums[j] + 1);
            }
        }
        nums.clear();
        for (int j = 0; j < digits.size(); ++j) {
            nums.push_back(digits[j]);
        }
        digits.clear();
    }
    result = nums.size() % mod;
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> nums;
        for (int j = 0; j < n.length(); ++j) {
            nums.push_back(convertCharToNum(n[j]));
        }
        int result = calculate(nums, m);
        cout << result << endl;
    }
}
