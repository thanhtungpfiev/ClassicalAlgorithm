/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/19/2021
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
    int rob(vector<int>& nums) {
        int result = 0;
        vector<int> d(nums.size(), -1);
        if (nums.size() == 1) {
            result = nums[0];
        } else if (nums.size() == 2) {
            result = max(nums[0], nums[1]);
        } else {
            d[0] = nums[0];
            d[1] = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); ++i) {
                d[i] = max(nums[i] + d[i - 2], d[i - 1]);
            }
            result = d[nums.size() - 1];

        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    int result = s.rob(nums);
    cout << result << endl;
    return 0;
}
