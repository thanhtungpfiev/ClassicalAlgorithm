/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/14/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                ++i;
            }
            ++j;
        }
        return i;
    }
};

int main()
{
    Solution so;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    int result = so.findContentChildren(g, s);
    cout << result << endl;
    return 0;
}
