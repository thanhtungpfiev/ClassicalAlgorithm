#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int score(vector<int> &a, vector<int> &b)
    {
        int runningSum = 0, maxi = 0;
        int sum = accumulate(a.begin(), a.end(), 0);

        for (int i = 0; i < a.size(); i++)
        {
            runningSum += b[i] - a[i];
            if (runningSum < 0)
                runningSum = 0;
            maxi = max(maxi, runningSum);
        }

        return sum + maxi;
    }

    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        return max(score(nums1, nums2), score(nums2, nums1));
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums1 = {60,60,60}, nums2 = {10,90,10};
    cout << sl.maximumsSplicedArray(nums1, nums2) << endl;
    return 0;
}