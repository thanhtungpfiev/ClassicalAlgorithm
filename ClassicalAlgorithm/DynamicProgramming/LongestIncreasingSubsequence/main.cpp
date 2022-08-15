/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/4/2022
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

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> length(nums.size());
        int best = 0;
        for (int k = 0; k < nums.size(); ++k)
        {
            length[k] = 1;
            for (int i = 0; i < k; ++i)
            {
                if (nums[i] < nums[k])
                {
                    length[k] = max(length[k], length[i] + 1);
                }
            }
            best = max(best, length[k]);
        }
        return best;
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        for (int i = 0; i < nums.size(); ++i)
        {
            int curr = nums[i];
            auto it = lower_bound(lis.begin(), lis.end(), curr);
            if (it == lis.end())
            {
                lis.push_back(curr);
            }
            else
            {
                *it = curr;
            }
        }
        return lis.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
    nums = {0, 1, 0, 3, 2, 3};
    cout << s.lengthOfLIS(nums) << endl;
    nums = {7, 7, 7, 7, 7, 7, 7};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}
