/*
 * File: main.cpp
 * Project: K-thElementOfTwoSortedArrays
 * File Created: Sunday, 5th June 2022 10:55:17 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <queue>

using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int result = -1;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (int i = 0; i < m; i++)
    {
        pq.push(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(arr2[i]);
    }
    for (int i = 0; i < k; i++)
    {
        result = pq.top();
        pq.pop();
    }
    return result;
}

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};

    int k = 5;
    cout << kth(arr1, arr2, arr1 + 5, arr2 + 4,  k - 1);
    return 0;
}

int main(int argc, char **argv)
{
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k = 5;
    cout << kth(arr1, arr2, 5, 4, k) << endl;
    int arr3[] = {100, 112, 256, 349, 770};
    int arr4[] = {72, 86, 113, 119, 265, 445, 892};
    int k1= 7;
    cout << kth(arr3, arr4, 5, 7, k1) << endl;

    return 0;
}