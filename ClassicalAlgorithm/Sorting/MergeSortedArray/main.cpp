/*
 * File: main.cpp
 * Project: MergeSortedArray
 * File Created: Tuesday, 7th June 2022 9:21:33 am
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m, j = 0; j < n; ++i, ++j)
        {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    sl.merge(nums1, m, nums2, n);
    nums1 = {1};
    m = 1;
    nums2 = {};
    n = 0;
    sl.merge(nums1, m, nums2, n);
    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    sl.merge(nums1, m, nums2, n);
    return 0;
}