/*
 * File: main.cpp
 * Project: SplitArrayIntoConsecutiveSubsequences
 * File Created: Friday, 19th August 2022 2:19:28 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        // This is a greedy approach. The whole idea is to first look for an existing group
        // to join for the current num. If no, then create a new group.
        // Here a group means group of 3 or more numbers as mentioned in question description.

        // This hashmap tells us about whether a number in num is available for a job or not
        unordered_map<int, int> avaibilityMap;

        // This hashmap tells a number (say x), if there is a job vacancy for them
        unordered_map<int, int> wantMap;

        // We store the count of every num in nums into avaibilityMap. Basically, a number's count is the avaibility of it.
        for (auto i : nums)
        {
            avaibilityMap[i]++;
        }

        // // We iterate through each number in the nums array. Remember the story ? So, treat them like a person.
        for (auto i : nums)
        {
            // First we check if our current num/person is available. If it is not we just continue with next num/person
            if (avaibilityMap[i] <= 0)
            {
                continue;
            }
            // If the person is available, first we check if there is a job vacancy for him/her. Basically, is someone looking for him/her?
            else if (wantMap[i] > 0)
            {
                // Yes, someone is looking, so we decrease the avaibility count of that number
                avaibilityMap[i]--;

                // we also decrease its count from the job vacancy space / wantMap
                wantMap[i]--;

                // Then as a goodwill, he/she will also create a job vacancy for (num[i]+1) in job vacancy space / wantMap, as we need consecutive numbers only
                wantMap[i + 1]++;
            }
            // Ooh, we are here means nums[i] was not able to find a job.
            // so, nums[i] tries to start his/her own company by checking avaibility of his/her friends i.e. (nums[i]+1) and (nums[i]+2)
            else if (avaibilityMap[i + 1] > 0 && avaibilityMap[i + 2] > 0)
            {
                // Yay! both 2 friends are available. Let's start a company.
                // So we decrease the avaibility count of nums[i], (nums[i]+1) and (nums[i]+2) from the
                // avaibilityMap
                avaibilityMap[i]--;
                avaibilityMap[i + 1]--;
                avaibilityMap[i + 2]--;

                // Also, as a goodwill, we create a new job vacancy for (nums[i]+3), as we need consecutive numbers only
                wantMap[i + 3]++;
            }
            // Bad luck case, nums[i] not able to start his/her company, so just return false
            else
            {
                return false;
            }
        }
        // All good till here so we return true
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: nums = [1,2,3,3,4,5]
    // Output: true
    // Explanation: nums can be split into the following subsequences:
    // [1,2,3,3,4,5] --> 1, 2, 3
    // [1,2,3,3,4,5] --> 3, 4, 5

    // Input: nums = [1,2,3,3,4,4,5,5]
    // Output: true
    // Explanation: nums can be split into the following subsequences:
    // [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
    // [1,2,3,3,4,4,5,5] --> 3, 4, 5

    // Input: nums = [1,2,3,4,4,5]
    // Output: false
    // Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
    return 0;
}