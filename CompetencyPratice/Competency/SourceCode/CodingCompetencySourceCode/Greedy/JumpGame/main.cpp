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

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndx = 0;
        int result = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxIndx >= nums.size() - 1) {
                result = true;
                break;
            }
            if (maxIndx < i) {
                result = false;
                break;
            }
            maxIndx = max(i + nums[i], maxIndx);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2, 3, 1, 1, 4};
    int result = s.canJump(nums);
    cout << result << endl;
    return 0;
}
