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

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        int N = intervals.size();
        std::vector<bool> isValid(N, true);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    isValid[i] = false;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            if (isValid[i]) {
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
