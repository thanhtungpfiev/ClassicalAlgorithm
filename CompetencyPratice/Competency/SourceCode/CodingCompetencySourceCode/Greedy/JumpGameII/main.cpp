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
    int jump(vector<int>& nums) {
        int step = 0;
        for (int l = 0, r = 0; r < nums.size() - 1; ++step) {
            int farthestJump = 0;
            for (int i = l; i <= r; ++i) {
                farthestJump = max(farthestJump, i + nums[i]);

            }
            l = r + 1;
            r = farthestJump;
        }
        return step;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = s.jump(nums);
    cout << result << endl;
    return 0;
}
