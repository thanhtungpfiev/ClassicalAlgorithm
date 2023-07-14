/*
 * File: main.cpp
 * Project: FindMaxInSortedRotatedArray
 * File Created: Sunday, 5th June 2022 8:51:21 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

// Function to return the maximum element
int findMax(int arr[], int low, int high)
{

    if (high == low)
        return arr[low];

    // Find mid
    int mid = low + (high - low) / 2;
    // Check if mid reaches 0 ,it is greater than next element or not
    if (mid == 0 && arr[mid] > arr[mid + 1])
    {
        return arr[mid];
    }

    // Check if mid itself is maximum element
    if (mid < high && arr[mid + 1] < arr[mid] && mid > 0 && arr[mid] > arr[mid - 1])
    {
        return arr[mid];
    }

    // Decide whether we need to go to
    // the left half or the right half
    if (arr[low] > arr[mid])
    {
        return findMax(arr, low, mid - 1);
    }
    else
    {
        return findMax(arr, mid + 1, high);
    }
}

int main(int argc, char **argv)
{
    int arr[] = {3, 4, 5, 1, 2};
    cout << findMax(arr, 0, 4) << endl;
    cout << findMax1(arr, 0, 4) << endl;
    int arr1[] = {1, 2, 3};
    cout << findMax(arr1, 0, 2) << endl;
    cout << findMax1(arr1, 0, 2) << endl;
    return 0;
}