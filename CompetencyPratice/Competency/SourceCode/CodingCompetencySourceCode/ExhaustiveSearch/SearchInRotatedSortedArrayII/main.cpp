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
bool isBinarySearchHelpful(vector<int>& nums, int start, int target) {
    return nums[start] != target;
}
bool search(vector<int>& nums, int target) {
    bool result = false;
    int n = nums.size();
    if (n == 0) {
        result =  false;
    } else {
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = true;
                break;
            }
            if (!isBinarySearchHelpful(nums, start, nums[mid])) {
                start++;
                continue;
            }
            bool pivotMid = isExistInFirst(nums, start, nums[mid]);
            bool pivotTarget = isExistInFirst(nums, start, target);
            if ((pivotMid == true && pivotTarget == false)
                    || (pivotMid == true && pivotTarget == true && nums[mid] < target)
                    || (pivotMid == false && pivotTarget == false && nums[mid] < target))
            {
                start = mid + 1;
            } else  if ((pivotMid == false && pivotTarget == true)
                        || (pivotMid == true && pivotTarget == true && nums[mid] > target)
                        || (pivotMid == false && pivotTarget == false && nums[mid] > target)) {
                end = mid - 1;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};
    int target  = 0;
    cout << search(nums, target) << endl;
    return 0;
}
