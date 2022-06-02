/*
 * File: main.cpp
 * Project: FindMedianOfTwoSortedArrays
 * File Created: Thursday, 2nd June 2022 4:17:37 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

int findMedian(std::vector<int> &dataFirst, int sizeFirst, std::vector<int> &dataSecond, int sizeSecond)
{
    int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) % 2) / 2;
    int i = 0, j = 0, count = 0;
    while (count < medianIndex - 1)
    {
        if (i < sizeFirst - 1 && dataFirst[i] < dataSecond[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    if (dataFirst[i] < dataSecond[j])
    {
        return dataFirst[i];
    }
    else
    {
        return dataSecond[j];
    }
}

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0, m1 = -1, m2 = -1;
        for (int count = 0; count <= (nums1.size() + nums2.size()) / 2; ++count)
        {
            m2 = m1;
            if (i != nums1.size() && j != nums2.size())
            {
                m1 = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
            }
            else if (i < nums1.size())
            {
                m1 = nums1[i++];
            }
            else
            {
                m1 = nums2[j++];
            }
        }
        if ((nums1.size() + nums2.size()) % 2)
        {
            return m1;
        }
        else
        {
            return (m1 + m2) / 2.0;
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sl.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sl.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}