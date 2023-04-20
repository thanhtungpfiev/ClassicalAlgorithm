/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/6/2021
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
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        int N = intervals.size();
        std::sort(intervals.begin(), intervals.end(), myComp);

        int max = -1;
        for (int i = 0; i < N; ++i) {
            if (intervals[i][1] > max) {
                max = intervals[i][1];
                result++;
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    Solution s;
    int result = s.removeCoveredIntervals(intervals);
    cout << result << endl;
    return 0;
}
