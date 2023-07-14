/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/5/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 ***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int best = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = max(sum + nums[i], nums[i]);
            best = max(sum, best);
        }
        return best;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sl.maxSubArray(nums) << endl;
    nums = {1};
    cout << sl.maxSubArray(nums) << endl;
    nums = {5, 4, -1, 7, 8};
    cout << sl.maxSubArray(nums) << endl;
    return 0;
}
