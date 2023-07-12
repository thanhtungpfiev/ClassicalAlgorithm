/*
 * File: main.cpp
 * Project: StepsToMakeArrayNonDecreasing
 * File Created: Monday, 6th June 2022 3:14:59 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    typedef pair<int, int> mPair;
    int totalSteps(vector<int> &nums)
    {
        int result = 0;
        stack<mPair> st;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int cnt = 0;
            while (!st.empty() && nums[i] > st.top().second)
            {
                cnt = max(cnt + 1, st.top().first);
                st.pop();
            }
            st.push(mPair(cnt, nums[i]));
            if (result < cnt)
            {
                result = cnt;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {5,3,4,4,7,3,6,11,8,5,11};
    cout << sl.totalSteps(nums) << endl;
    nums = {4,5,7,7,13};
    cout << sl.totalSteps(nums) << endl;

    return 0;
}