/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 7/27/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

bool isExistInFirst(vector<int>& nums, int start, int target) {
    return nums[start] <= target;
}

int search(vector<int>& nums, int target) {
    int result = -1;
    int size = nums.size();
    if (size > 0) {
        int start = 0;
        int end = size - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                break;
            } else {
                bool pivotMid = isExistInFirst(nums, start, nums[mid]);
                bool pivotTarget = isExistInFirst(nums, start, target);
                if ((pivotMid == true && pivotTarget == false)
                        || (pivotMid == true && pivotTarget == true && nums[mid] < target)
                        || (pivotMid == false && pivotTarget == false && nums[mid] < target)) {
                    start = mid + 1;
                } else if ((pivotMid == false && pivotTarget == true)
                        || (pivotMid == true && pivotTarget == true && nums[mid] > target)
                        || (pivotMid == false && pivotTarget == false && nums[mid] > target)) {
                    end = mid - 1;
                }
            }
        }
    }
    return result;
}

int binarSearch(vector<int>& nums, int start, int end, int target) {
    int result = -1;
    if (start < 0 || end >= nums.size()) {

    } else {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                break;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return result;
}

int search2(vector<int>& nums, int target) {
    int result = -1;
    int size = nums.size();
    if (size > 0) {
        int index = -1;
        int start = 0;
        int end = size - 1;
        // find pivot by binary search
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[size - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
                index = mid;
            }
        }
        // find target in 2 arrays
        if (target == nums[index]) {
            result = index;
        } else if (target > nums[size - 1]) {
            result = binarSearch(nums, 0, index - 1, target);
        } else {
            result = binarSearch(nums, index, size - 1, target);
        }
    }
    return result;

}

int main()
{
//    vector<int> nums1 = {4,5,6,7,0,1,2};
//    int target1 = 0;
//    cout << search(nums1, target1) << endl;
//    cout << search2(nums1, target1) << endl;

//    vector<int> nums2 = {4,5,6,7,0,1,2};
//    int target2 = 3;
//    cout << search(nums2, target2) << endl;
//    cout << search2(nums2, target2) << endl;

//    vector<int> nums3 = {1};
//    int target3 = 0;
//    cout << search(nums3, target3) << endl;
//    cout << search2(nums3, target3) << endl;

    vector<int> nums4 = {1, 3};
    int target4 = 3;
    cout << search(nums4, target4) << endl;
    cout << search2(nums4, target4) << endl;

    return 0;
}
