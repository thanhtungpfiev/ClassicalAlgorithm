/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/20/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int bruteForce(const vector<int>& arr, int target) {
    int result = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (target == arr[i]) {
            result = i;
            break;
        } else {
            if (i == 0 && target < arr[i]) {
                result = i;
                break;
            }
            if (i == arr.size() - 1 && target > arr[i]) {
                result = i + 1;
                break;
            }
            if (i >= 0 && i < arr.size() - 1 && target > arr[i] && target < arr[i + 1]) {
                result = i + 1;
                break;
            }
        }
    }
    return result;
}

int binarySearch(const vector<int>& arr, int target)
{
    int result = 0;
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (target == arr[mid]) {
            result = mid;
            break;
        } else if (target < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (result == 0) {
        result = lo;
    }
    return result;
}

int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << binarySearch(nums, target) << endl;
    target = 1;
    cout << binarySearch(nums, target) << endl;
    target = 6;
    cout << binarySearch(nums, target) << endl;

    target = 2;
    cout << binarySearch(nums, target) << endl;
    target = 7;
    cout << binarySearch(nums, target) << endl;
    target = 0;
    cout << binarySearch(nums, target) << endl;

    return 0;
}
