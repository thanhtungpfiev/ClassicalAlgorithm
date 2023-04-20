/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/19/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int maxIn3Elementh(int sum1, int sum2, int sum3)
{
    int maxSum = sum1;
    maxSum = max(sum1, sum2);
    maxSum = max(maxSum, sum3);
    return maxSum;
}
int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; ++i) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return maxIn3Elementh(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h) {
        return arr[l];
    }
    int m = (l + h) / 2;
    return maxIn3Elementh(maxSubArraySum(arr, l, m),
                            maxSubArraySum(arr, m + 1, h),
                            maxCrossingSum(arr, l, m, h));
}

int main()
{
    /* brute forece
//    vector<int> arr = {1,2,3,-2,5};
    vector<int> arr = {-1,-2,-3,-4};

    int maxsum = arr[0];
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i; j < arr.size(); ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    cout << maxsum << endl;
    */

    /* devide and conqure

    int n = 5;
    int arr[] = {1,2,3,-2,5};
    int n1 = 4;
    int arr1[] = {-1,-2,-3,-4};
    cout << maxSubArraySum(arr, 0, n - 1);
    cout << endl;
    cout << maxSubArraySum(arr1, 0, n1 - 1);
    int n2 = 9;
    int arr2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << endl;
    cout << maxSubArraySum(arr2, 0, n2 - 1);
    cout << endl;
    */

    /* Kadane Algorithm
     */
    int n = 5;
    int arr[] = {1,2,3,-2,5};
    int max_so_far = INT8_MIN, max_ending_here = 0;
    for (int i = 0; i < n; ++i) {
        max_ending_here += arr[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    cout << max_so_far << endl;

}
